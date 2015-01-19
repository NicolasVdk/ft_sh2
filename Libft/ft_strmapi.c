/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 21:29:28 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/09 19:22:35 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	k;
	unsigned int	i;
	char			*dst;

	i = 0;
	k = 0;
	dst = NULL;
	if (s != NULL && f != NULL)
	{
		k = ft_strlen(s);
		dst = (char *)malloc(sizeof(char) * k + 1);
		while (k > i)
		{
			dst[i] = (*f)(i, s[i]);
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
