/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 01:33:21 by nverdonc          #+#    #+#             */
/*   Updated: 2015/01/19 15:52:02 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int		ft_builtin(char *command, t_env **lenv)
{
	if (ft_strncmp(command, "cd", 2) == 0)
	{
		ft_command_cd(command, *lenv);
		return (1);
	}
	if (ft_strncmp(command, "setenv", 6) == 0)
	{
		if (ft_numberofav(command) == 3)
			ft_command_setenv(*lenv, command);
		else
			ft_putendl_fd("Invalid argument | use > setenv ID VALUE <", 2);
		return (1);
	}
	if (ft_strcmp(command, "env") == 0)
	{
		ft_command_env(*lenv);
		return (1);
	}
	if (ft_strncmp(command, "unsetenv", 8) == 0)
	{
		ft_command_unsetenv(lenv, ft_strsplit(command, ' '), \
							ft_numberofav(command));
		return (1);
	}
	return (0);
}

void	endprocess(pid_t pid)
{
	int		status;

	status = 0;
	waitpid(pid, &status, 0);
}

void	ft_exec(char *path, char *name, char *command, t_env *lenv)
{
	pid_t				pid;
	char				**av;
	char				*bin;
	struct sigaction	sig;
	char				**env;

	av = ft_strsplit(command, ' ');
	bin = ft_strpathcat(path, name);
	env = ft_recreate_env(lenv);
	if (!(pid = fork()))
	{
		sig.sa_handler = SIG_DFL;
		sigaction(SIGINT, &sig, NULL);
		if (!isexec(bin) || execve(bin, av, env) == -1)
		{
			ft_putstr_fd(av[0], 2);
			ft_putendl_fd(" : Fichier introuvable ou invalide", 2);
			exit(EXIT_FAILURE);
		}
	}
	else
		endprocess(pid);
	ft_strdeld(&av);
	ft_strdeld(&env);
	ft_strdel(&bin);
}

int		ft_bin(char *command, char **path, t_env *lenv)
{
	DIR				*rep;
	struct dirent	*lecture;
	char			**av;

	av = ft_strsplit(command, ' ');
	while (*path)
	{
		if (((rep = opendir(*path)) != NULL))
		{
			while ((lecture = readdir(rep)))
			{
				if (lecture->d_type != 4 && ft_strcmp(av[0], \
					lecture->d_name) == 0)
				{
					ft_exec(*path, lecture->d_name, command, lenv);
					ft_strdeld(&av);
					return (1);
				}
			}
			closedir(rep);
		}
		path++;
	}
	ft_strdeld(&av);
	return (0);
}

int		ft_entry(char *command, t_env **lenv, char **path)
{
	char	**commande;

	commande = ft_strsplit(command, ';');
	while (*commande)
	{
		while (ft_isspace(**commande))
			(*commande)++;
		if (ft_strcmp(*commande, "") == 0)
			return (0);
		else if (ft_strcmp(*commande, "exit") == 0)
			exit(1);
		else if (ft_strncmp(*commande, "./", 2) == 0 || \
				ft_strncmp(*commande, "/", 1) == 0)
			ft_basic_process(*commande, *lenv);
		else if (ft_builtin(*commande, lenv) == 1)
			(void)*commande;
		else if (ft_bin(*commande, path, *lenv) == 1)
			(void)*commande;
		else
			return (-1);
		commande++;
	}
	return (0);
}
