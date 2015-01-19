/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:30:10 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/09 21:50:53 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strtrim(char const *s)
{
	char		*str;
	size_t		size;
	size_t		i;

	str = NULL;
	i = 0;
	size = 0;
	if (s != NULL)
	{
		size = ft_strlen(s);
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && i < size)
			i++;
		while ((s[size - 1] == ' ' || s[size - 1] == '\t' || \
				s[size - 1] == '\n') && size > 0)
			size--;
		if (size != 0 && i != ft_strlen(s))
		{
			str = ft_strsub(s, i, (size - i));
			return (str);
		}
		else
			return (ft_strdup(""));
	}
	return (NULL);
}
