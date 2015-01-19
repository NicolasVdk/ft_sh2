/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:51:12 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/09 16:27:20 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 != NULL && s2 != NULL)
	{
		if (n == 0)
			return (1);
		while (*s1 == *s2 && *s1 && *s2 && n-- > 1)
		{
			s1++;
			s2++;
		}
		if (*s1 == *s2)
			return (1);
	}
	return (0);
}
