/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:19:07 by nverdonc          #+#    #+#             */
/*   Updated: 2014/11/12 20:40:49 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void		*memory;
	char		*ptr;
	size_t		i;

	memory = (void *)malloc(size);
	ptr = memory;
	i = 0;
	if (memory != NULL)
	{
		while (i < size)
		{
			i++;
			*ptr = 0;
			ptr++;
		}
	}
	return (memory);
}
