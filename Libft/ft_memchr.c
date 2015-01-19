/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:35:22 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/07 17:41:49 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char*)s;
	if (s && n > 0)
	{
		while (i < n)
		{
			if (ptr[i] == (unsigned char)c)
			{
				return ((void *)(ptr + i));
			}
			i++;
		}
	}
	return (NULL);
}
