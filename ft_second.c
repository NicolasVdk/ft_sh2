/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 07:56:33 by nverdonc          #+#    #+#             */
/*   Updated: 2015/01/26 17:06:47 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		ft_numberofav(char *command)
{
	char	**split;
	int		i;

	split = ft_strsplit(command, ' ');
	i = 0;
	while (split[i])
		i++;
	ft_strdeld(&split);
	return (i);
}

void	ft_pwd_change(char *newpwd, t_env *lenv)
{
	char	*pwd;
	char	*oldpwd;
	char	*npwd;

	npwd = ft_strstr(newpwd, ft_return_env(lenv, "HOME"));
	if (npwd == NULL)
		npwd = newpwd;
	oldpwd = ft_strjoin("setenv OLDPWD ", ft_return_env(lenv, "PWD"));
	pwd = ft_strjoin("setenv PWD ", npwd);
	ft_command_setenv(lenv, oldpwd);
	ft_command_setenv(lenv, pwd);
	ft_strdel(&oldpwd);
	ft_strdel(&pwd);
	ft_strdel(&newpwd);
}

void	ft_basic_process(char *command, t_env *lenv)
{
	pid_t	pid;
	char	**av;
	char	**env;

	av = ft_strsplit(command, ' ');
	env = ft_recreate_env(lenv);
	if (!(pid = fork()))
	{
		ft_signal();
		if (!isexec(av[0]) || execve(av[0], av, env) == -1)
			ft_error(command, 2);
	}
	else
		endprocess(pid);
	ft_strdeld(&env);
	ft_strdeld(&av);
}

t_env	*ft_list_add_env(t_env *lenv, char *env)
{
	t_env	*newelem;
	t_env	*tmp;

	newelem = (t_env *)malloc(sizeof(t_env));
	newelem->elem = ft_strdup(env);
	newelem->next = NULL;
	if (lenv == NULL)
		return (newelem);
	else
	{
		tmp = lenv;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newelem;
		return (lenv);
	}
}

t_env	*ft_list_env(char **env)
{
	t_env	*lenv;
	char	**command;

	while (*env)
	{
		lenv = ft_list_add_env(lenv, *env);
		env++;
	}
	command = ft_strsplit("unsetenv PS1", ' ');
	ft_command_unsetenv(&lenv, command, 2);
	lenv = ft_list_add_env(lenv, "PS1=$>");
	return (lenv);
}
