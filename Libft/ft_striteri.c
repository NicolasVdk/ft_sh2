/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 21:24:22 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/09 19:21:05 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned		k;
	unsigned int	i;

	i = 0;
	k = 0;
	if (s != NULL && f != NULL)
	{
		k = ft_strlen(s);
		while (k > i)
		{
			(*f)(i, s);
			s++;
			i++;
		}
	}
}
