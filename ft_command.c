/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 05:45:09 by nverdonc          #+#    #+#             */
/*   Updated: 2015/01/14 20:41:47 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_command_cd(char *command, t_env *lenv)
{
	char	**av;
	char	*pwd;

	pwd = NULL;
	av = ft_strsplit(command, ' ');
	if (ft_numberofav(command) == 1 && !chdir(ft_return_env(lenv, "HOME")))
		pwd = ft_strdup(ft_return_env(lenv, "HOME"));
	else if (ft_numberofav(command) == 2 && ft_strcmp(av[1], "-") == 0)
		pwd = ft_oldpwd_cd(lenv);
	else if (ft_numberofav(command) == 2)
	{
		if (chdir(av[1]))
		{
			ft_putstr_fd("cd: invalid argument : ", 2);
			ft_putendl_fd(av[1], 2);
		}
		pwd = getcwd(pwd, BUF_SIZE);
	}
	else
		ft_putendl_fd("cd: invalid entry", 2);
	if (pwd != NULL)
		ft_pwd_change(pwd, lenv);
	ft_strdeld(&av);
}

int		ft_command_env(t_env *lenv)
{
	t_env	*tmp;

	tmp = lenv;
	while (tmp != NULL)
	{
		ft_putendl(tmp->elem);
		if (tmp->next != NULL)
			tmp = tmp->next;
		else
			break ;
	}
	return (0);
}

void	ft_command_setenv(t_env *lenv, char *commande)
{
	char		**command;
	char		*line;
	char		*tmpline;
	t_env		*tmp;

	command = ft_strsplit(commande, ' ');
	tmp = lenv;
	tmpline = ft_strjoin(command[1], "=");
	line = ft_strjoin(tmpline, command[2]);
	ft_strdel(&tmpline);
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->elem, command[1], ft_strlen(command[1])) == 0 \
			&& tmp->elem[ft_strlen(command[1])] == '=')
		{
			free(tmp->elem);
			tmp->elem = line;
			break ;
		}
		if (tmp->next != NULL)
			tmp = tmp->next;
		else
			lenv = ft_list_add_env(lenv, line);
	}
	ft_strdeld(&command);
}

t_env	*ft_list_add_env(t_env *lenv, char *env)
{
	t_env	*newelem;
	t_env	*tmp;

	newelem = malloc(sizeof(t_env));
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

	while (*env)
	{
		lenv = ft_list_add_env(lenv, *env);
		env++;
	}
	return (lenv);
}
