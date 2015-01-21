/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 07:56:33 by nverdonc          #+#    #+#             */
/*   Updated: 2015/01/21 15:50:55 by nverdonc         ###   ########.fr       */
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

char	*ft_return_env(t_env *lenv, char *var)
{
	t_env	*tmp;

	tmp = lenv;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->elem, var, ft_strlen(var)) == 0 && \
			tmp->elem[ft_strlen(var)] == '=')
			return (&tmp->elem[ft_strlen(var) + 1]);
		if (tmp->next != NULL)
			tmp = tmp->next;
		else
			break ;
	}
	return ("");
}

void	ft_command_unsetenv(t_env **lenv, char **command, int ac)
{
	t_env	*back;
	t_env	*tmp;

	back = NULL;
	tmp = *lenv;
	if (ac == 2)
		while (tmp != NULL)
		{
			if (ft_strncmp(tmp->elem, command[1], ft_strlen(command[1])) == 0 \
				&& tmp->elem[ft_strlen(command[1])] == '=')
			{
				ft_strdel(&tmp->elem);
				if (back != NULL)
					free(back->next);
				else
					*lenv = tmp->next;
				back->next = tmp->next;
				break ;
			}
			back = tmp;
			tmp = tmp->next;
		}
	else
		ft_putendl_fd("Invalid arguments", 2);
	ft_strdeld(&command);
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
