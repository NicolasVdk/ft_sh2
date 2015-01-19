/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:33:18 by nverdonc          #+#    #+#             */
/*   Updated: 2014/12/27 18:26:58 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		i;

	i = 0;
	if (src != NULL)
	{
		while (*src != '\0' && n > i)
		{
			*dst++ = *src++;
			i++;
		}
		while (n > i)
		{
			*dst++ = '\0';
			i++;
		}
	}
	return (dst - i);
}
