/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:42:39 by nverdonc          #+#    #+#             */
/*   Updated: 2014/12/26 23:14:34 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*fresh;
	size_t		i;

	fresh = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	if (s != NULL && fresh != NULL)
	{
		while (len > i && s[start] != '\0')
			fresh[i++] = s[start++];
		while (len > i)
			fresh[i++] = '\0';
		fresh[i] = '\0';
		return (fresh);
	}
	return (NULL);
}
