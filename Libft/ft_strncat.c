/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:28:34 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/09 13:30:08 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*tmp;
	size_t	b;

	tmp = s1;
	b = 0;
	if (n > 0)
	{
		while (*s1)
			s1++;
		while (*s2 && b++ != n)
			*s1++ = *s2++;
		*s1 = '\0';
	}
	return (tmp);
}
