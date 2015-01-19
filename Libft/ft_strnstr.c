/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:24:41 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/09 19:23:32 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (*s2)
	{
		while (ft_strncmp(s1, s2, ft_strlen(s2)) != 0 && *s1 != '\0' && \
				n-- != 0)
		{
			s1++;
		}
		if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0 && n >= ft_strlen(s2))
			return ((char *)s1);
		else
			return (NULL);
	}
	return ((char *)s1);
}
