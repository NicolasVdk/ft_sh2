/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 12:29:53 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/09 13:28:04 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strlen(const char *str)
{
	const char		*tmp;

	if (str != NULL)
	{
		tmp = str;
		while (*tmp)
			tmp++;
		return (tmp - str);
	}
	return (0);
}
