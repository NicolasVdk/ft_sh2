/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:58:45 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/07 14:57:00 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*tmp_dst;
	char const	*tmp_src;

	i = 0;
	tmp_dst = dst;
	tmp_src = src;
	if (src != NULL)
	{
		while (tmp_src != '\0' && i < n)
		{
			i++;
			*tmp_dst = *tmp_src;
			tmp_dst++;
			tmp_src++;
		}
	}
	else
		return (NULL);
	return (dst);
}
