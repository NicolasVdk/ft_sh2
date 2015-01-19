/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 01:29:36 by nverdonc          #+#    #+#             */
/*   Updated: 2015/01/15 20:19:39 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	ft_error(char *command, int error)
{
	char	**commande;

	commande = ft_strsplit(command, ' ');
	if (error == 1)
	{
		ft_putstr_fd(commande[0], 2);
		ft_putendl_fd(" : Commande inconnue", 2);
	}
	ft_strdeld(&commande);
}
