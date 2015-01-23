/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 17:33:29 by nverdonc          #+#    #+#             */
/*   Updated: 2015/01/15 20:41:39 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

char	**ft_recreate_env(t_env *env)
{
	t_env	*tmp;
	char	**tab_env;
	int		i;

	tmp = env;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	tab_env = malloc(sizeof(char **) * i + 1);
	tmp = env;
	i = 0;
	while (tmp != NULL)
	{
		tab_env[i++] = ft_strdup(tmp->elem);
		tmp = tmp->next;
	}
	tab_env[i] = '\0';
	return (tab_env);
}
