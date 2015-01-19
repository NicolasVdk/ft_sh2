/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:34:26 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/08 18:11:49 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	if (*s2)
	{
		while (ft_strncmp(s1, s2, ft_strlen(s2)) != 0 && *s1 != '\0')
			s1++;
		if (*s1 == '\0')
			return (NULL);
	}
	return ((char *)s1);
}
