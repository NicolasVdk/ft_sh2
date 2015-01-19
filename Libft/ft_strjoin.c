/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:57:05 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/09 19:22:07 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;

	fresh = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		fresh = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (s1)
			fresh = ft_strcpy(fresh, s1);
		if (s2)
			fresh = ft_strcat(fresh, s2);
		return (fresh);
	}
	return (NULL);
}
