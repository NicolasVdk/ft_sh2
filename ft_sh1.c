/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 21:03:00 by nverdonc          #+#    #+#             */
/*   Updated: 2015/01/26 17:09:44 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#include "get_next_line.h"

char	*ft_oldpwd_cd(t_env *lenv)
{
	if (ft_strcmp(ft_return_env(lenv, "OLDPWD"), "") != 0)
	{
		if (chdir(ft_return_env(lenv, "OLDPWD")))
			ft_putendl_fd("OLDPWD Invalid", 2);
		else
			return (ft_strdup(ft_return_env(lenv, "OLDPWD")));
	}
	else
		ft_putendl_fd("OLDPWD inexistant", 2);
	return (NULL);
}

void	ft_putps1(char *ps1, t_env *lenv)
{
	int		i;

	i = 0;
	while (ps1[i])
	{
		if (ps1[i + 1] && ps1[i] == '%')
		{
			if (ps1[i + 1] == 'p')
				ft_putstr(ft_return_env(lenv, "PWD"));
			else if (ps1[i + 1] == 'u')
				ft_putstr(ft_return_env(lenv, "USER"));
			else if (ps1[i + 1] == 'g')
				ft_putstr(ft_return_env(lenv, "GROUP"));
			else if (ps1[i + 1] == 'm')
				ft_putstr(ft_return_env(lenv, "MAIL"));
			else
				ft_putchar('%');
			i = i + 2;
		}
		else
			ft_putchar(ps1[i++]);
	}
	ft_putchar(' ');
}

void	ft_sh1(char **env, int	fd)
{
	char	*buf;
	char	**path;
	int		ret;
	t_env	*lenv;

	buf = NULL;
	lenv = ft_list_env(env);
	while (1)
	{
		path = ft_strsplit(ft_return_env(lenv, "PATH"), ':');
		fd == 0 ? ft_putps1(ft_return_env(lenv, "PS1"), lenv) : 1;
		while ((ret = get_next_line(fd, &buf)) == -1)
			;
		if (!ret)
			return ;
		if (buf)
			ft_entry(buf, &lenv, path);
		ft_strdeld(&path);
		ft_strdel(&buf);
	}
}

int		main(int ac, char **av, char **env)
{
	struct sigaction sig;

	if (ac == 1)
	{
		sig.sa_flags = 0;
		sig.sa_handler = SIG_IGN;
		sigaction(SIGINT, &sig, NULL);
		ft_sh1(env, 0);
	}
	else
		ft_treat_file(av[1], env);
	return (0);
}
