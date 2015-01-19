/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:30:24 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/09 21:50:44 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static size_t	ft_nb_pt(const char *s, char c)
{
	size_t		i;
	size_t		string;

	string = 0;
	i = 0;
	while (*s != '\0')
	{
		if (string == 1 && *s == c)
			string = 0;
		if (string == 0 && *s != c)
		{
			string = 1;
			i++;
		}
		s++;
	}
	return (i);
}

static size_t	ft_next_pt(const char *s, char c)
{
	size_t		i;

	i = 0;
	while (*s != c && *s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tmp;
	size_t		nb_part;
	size_t		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	nb_part = ft_nb_pt((const char *)s, c);
	tmp = (char **)malloc(sizeof(char *) * (nb_part + 1));
	if (tmp == NULL)
		return (NULL);
	while (nb_part--)
	{
		while (*s == c && *s != '\0')
			s++;
		tmp[i] = ft_strsub((const char *)s, 0, ft_next_pt((const char *)s, c));
		if (tmp[i] == NULL)
			return (NULL);
		s = s + ft_next_pt(s, c);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
