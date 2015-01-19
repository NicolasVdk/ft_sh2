/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:52:24 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/10 15:01:26 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_white_space(int c)
{
	if (c == '\n' || \
		c == '\v' || \
		c == '\t' || \
		c == '\r' || \
		c == '\f' || \
		c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		value;

	i = 0;
	result = 0;
	value = 0;
	while (str[i] && ft_white_space(str[i]) == 1 && ft_isdigit(str[i]) == 0)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		value = str[i];
		i++;
	}
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		result = result * 10;
		result = result + (str[i] - 48);
		i++;
	}
	if (value == '-')
		return (-result);
	return (result);
}
