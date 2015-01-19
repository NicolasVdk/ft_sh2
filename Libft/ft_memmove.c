/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:52:40 by nverdonc          #+#    #+#             */
/*   Updated: 2014/12/27 17:56:34 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp_dst;
	const char	*tmp_src;

	tmp_src = src;
	tmp_dst = dst;
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	tmp_src += len;
	tmp_dst += len;
	while (len--)
		*--tmp_dst = *--tmp_src;
	return (dst);
}
