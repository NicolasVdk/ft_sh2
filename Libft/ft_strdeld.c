/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdeld.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 12:48:40 by nverdonc          #+#    #+#             */
/*   Updated: 2015/01/14 13:06:35 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strdeld(char ***tab)
{
	int		i;

	i = 0;
	while ((*tab)[i] != NULL)
		free((*tab)[i++]);
	free(*tab);
	tab = NULL;
}
