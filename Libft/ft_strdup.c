/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:11:06 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/09 19:21:28 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;

	if (s1 != NULL)
	{
		dest = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
		return (ft_strcpy(dest, s1));
	}
	return (NULL);
}
