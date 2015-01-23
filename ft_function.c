/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 21:03:00 by nverdonc          #+#    #+#             */
/*   Updated: 2015/01/21 12:56:04 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

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

void	ft_signal()
{
	struct sigaction	sig;

	sig.sa_handler = SIG_DFL;
	sigaction(SIGINT, &sig, NULL);
}

int		isexec(char *path)
{
	struct stat		buf;

	lstat(path, &buf);
	return (buf.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH));
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
