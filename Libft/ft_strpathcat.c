/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpathcat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 17:05:28 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/26 17:13:17 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpathcat(char *path, char *filename)
{
	char	*dest;

	dest = ft_strnew(ft_strlen(path) + ft_strlen(filename) + 1);
	ft_strcat(dest, path);
	if (path[ft_strlen(path) - 1] != '/')
		ft_strcat(dest, "/");
	ft_strcat(dest, filename);
	return (dest);
}
