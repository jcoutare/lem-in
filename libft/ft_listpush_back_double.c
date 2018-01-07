/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listpush_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:27:19 by yguzman           #+#    #+#             */
/*   Updated: 2017/01/30 17:18:33 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int					list_push_back(t_list **list, void *content, size_t size)
{
	t_list			*new;
	t_list			*tmp;

	if ((new = malloc(sizeof(t_list))) == NULL)
		return (-1);
	new->next = NULL;
	new->prev = NULL;
	new->content = content;
	new->content_size = size;
	if (*list == NULL)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
	return (0);
}
