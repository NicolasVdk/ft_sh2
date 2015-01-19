/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:30:01 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/07 21:19:27 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int		k;
	int		i;

	i = 0;
	k = 0;
	if (s != NULL && f != NULL)
	{
		k = ft_strlen(s);
		while (k > i)
		{
			(*f)(s);
			s++;
			i++;
		}
	}
}
