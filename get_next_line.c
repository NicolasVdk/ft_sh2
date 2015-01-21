/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 13:15:11 by nverdonc          #+#    #+#             */
/*   Updated: 2015/01/21 12:53:46 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static unsigned int		ft_next_n(char *str)
{
	unsigned int		i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
	}
	return (i);
}

int			get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static	char	*end = NULL;
	char			*tmp;
	char			*tmp_free;
	int				ret;

	*line = NULL;
	tmp = end;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp_free = tmp;
		tmp = ft_strjoin(tmp, buf);
		if (tmp_free)
			ft_strdel(&tmp_free);
		if (ft_next_n(buf) != ft_strlen(buf))
			break ;
	}
	*line = ft_strsub(tmp, 0, ft_next_n(tmp));
	end = ft_strsub(tmp, ft_next_n(tmp) + 1, ft_strlen(tmp));
	ft_strdel(&tmp);
	if (**line == '\0')
		return (0);
	return (1);
}
