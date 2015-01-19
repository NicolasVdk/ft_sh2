/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 13:15:11 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/21 21:29:29 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_next_n(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
	}
	return (i);
}

static int	ft_end(char **line, char **end)
{
	char	*tmp;
	char	*buf;
	char	*tmp_buf;

	if (*end != NULL)
	{
		buf = ft_strdup(*end);
		ft_strdel(end);
		tmp_buf = buf;
		tmp = ft_strnew(ft_next_n(buf) + 1);
		*line = tmp;
		while (*buf && *buf != '\n')
			*tmp++ = *buf++;
		if (*buf == '\n')
		{
			*end = ft_strdup(buf + 1);
			free(tmp_buf);
			return (1);
		}
		free(tmp_buf);
	}
	return (0);
}

static int	ft_realloc(char **line, char **end, char *buf)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(*line) + ft_next_n(buf) + 1);
	if (*line != NULL)
	{
		tmp = ft_strcpy(tmp, *line);
		ft_strdel(line);
	}
	*line = tmp;
	tmp = tmp + ft_strlen(tmp);
	while (*buf && *buf != '\n')
		*tmp++ = *buf++;
	if (*buf == '\n')
	{
		*end = ft_strdup(buf + 1);
		return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static	char	*end = NULL;
	int				error;
	int				ret;

	if (fd < 0)
		return (-1);
	if ((error = ft_end(line, &end)) == -1)
		return (-1);
	else if (error == 1)
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if ((error = ft_realloc(line, &end, buf)) == -1)
			return (-1);
		else if (error == 1)
			return (1);
	}
	if (ret == 0 && end != NULL)
	{
		ft_strdel(&end);
		return (1);
	}
	return (0);
}
