/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:47:09 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/07 14:22:24 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_strclr(char *s)
{
	int		i;
	int		size_s;

	i = 0;
	size_s = 0;
	if (s != NULL)
	{
		size_s = ft_strlen(s);
		while (i < size_s)
		{
			s[i] = '\0';
			i++;
		}
	}
}
