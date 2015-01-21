/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 13:23:11 by nverdonc          #+#    #+#             */
/*   Updated: 2015/01/21 15:45:08 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#include "get_next_line.h"

void    ft_sh_files(char **env, int  fd)
{
	char    *buf;
	char    **path;
	t_env   *lenv;

	buf = NULL;
	lenv = ft_list_env(env);
	ft_command_setenv(lenv, "setenv PS1 $>");
	path = ft_strsplit(ft_return_env(lenv, "PATH"), ':');
	fd == 0 ? ft_putps1(ft_return_env(lenv, "PS1"), lenv) : 1;
	while (get_next_line(fd, &buf))
	{
		ft_entry(buf, &lenv, path);
		fd == 0 ? ft_putps1(ft_return_env(lenv, "PS1"), lenv) : 1;
		ft_strdeld(&path);
		path = ft_strsplit(ft_return_env(lenv, "PATH"), ':');
		ft_strdel(&buf);
	}
}

int		ft_treat(char *commande, t_env **lenv, char **path)
{
	if (ft_strcmp(commande, "") == 0)
		return (0);
	else if (ft_strcmp(commande, "exit") == 0)
		exit(1);
	else if (ft_strncmp(commande, "./", 2) == 0 || \
			 ft_strncmp(commande, "/", 1) == 0)
		ft_basic_process(commande, *lenv);
	else if (ft_builtin(commande, lenv) == 1)
		return (0);
	else if (ft_bin(commande, path, *lenv) == 1)
		return (0);
	else
		return (-1);
	return (0);
}

int		ft_treat_file(char *files, char **env)
{
	int		fd;

	if ((fd = open(files, O_RDONLY)) > 0)
		ft_sh_files(env, fd);
	else
		ft_error(files, 3);
	return (0);
}

void	ft_signal()
{
	struct sigaction	sig;

	sig.sa_handler = SIG_DFL;
	sigaction(SIGINT, &sig, NULL);
}
