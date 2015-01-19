/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:24:32 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/07 15:41:05 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*tmp_dst;
	char const	*tmp_src;

	tmp_dst = dst;
	tmp_src = src;
	if (src != NULL)
	{
		while (n-- != 0)
		{
			if (*tmp_src == c)
			{
				*tmp_dst++ = *tmp_src++;
				return (tmp_dst);
			}
			*tmp_dst++ = *tmp_src++;
		}
	}
	return (NULL);
}
