/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 19:30:22 by nverdonc          #+#    #+#             */
/*   Updated: 2014/12/05 04:36:53 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int		ft_size_n(int n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*tmp_n;
	char	*tmp;
	int		i;

	i = ft_size_n(n);
	tmp_n = (char *)malloc(sizeof(char) * i + 1);
	tmp = tmp_n;
	if (n == -2147483648)
		return ("-2147483648");
	if (n < 0)
	{
		n -= n * 2;
		tmp_n[0] = '-';
	}
	else if (n > 0)
		i--;
	tmp_n[i + 1] = '\0';
	while (n >= 10)
	{
		tmp_n[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	tmp_n[i] = (n + 48);
	return (tmp);
}
