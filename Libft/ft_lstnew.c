/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nverdonc <nverdonc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/27 18:52:00 by nverdonc          #+#    #+#             */
/*   Updated: 2014/12/27 19:23:35 by nverdonc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*elem;

	elem = (void *)malloc(content_size + 1);
	if (content == NULL)
	{
		elem = NULL;
		content_size = 0;
	}
	else
		elem = ft_memcpy(elem, content, content_size);
	list = (t_list *)malloc(sizeof(t_list));
	if (list != NULL)
	{
		list->content_size = content_size;
		list->next = NULL;
		list->content = elem;
	}
	return (list);
}
