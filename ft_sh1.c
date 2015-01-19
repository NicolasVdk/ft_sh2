/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 21:03:00 by nverdonc          #+#    #+#             */
/*   Updated: 2015/01/15 19:25:54 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"
#include "get_next_line.h"

int		ft_isspace(int c)
{
	if (c == '\n' || \
		c == '\v' || \
		c == '\t' || \
		c == '\r' || \
		c == '\f' || \
		c == ' ')
		return (1);
	return (0);
}

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
}

void	ft_sh1(char **env)
{
	char	*buf;
	char	**path;
	t_env	*lenv;

	lenv = ft_list_env(env);
	buf = NULL;
	ft_command_setenv(lenv, "setenv PS1 $>");
	path = ft_strsplit(ft_return_env(lenv, "PATH"), ':');
	ft_putps1(ft_return_env(lenv, "PS1"), lenv);
	while (get_next_line(0, &buf))
	{
		if ((ft_entry(buf, &lenv, path) != 0))
			ft_error(buf, 1);
		ft_putps1(ft_return_env(lenv, "PS1"), lenv);
		ft_strdeld(&path);
		path = ft_strsplit(ft_return_env(lenv, "PATH"), ':');
		ft_strdel(&buf);
	}
}

int		main(int ac, char **av, char **env)
{
	struct sigaction sig;

	(void)ac;
	(void)av;
	sig.sa_flags = 0;
	sig.sa_handler = SIG_IGN;
	sigaction(SIGINT, &sig, NULL);
	ft_sh1(env);
	return (0);
}
