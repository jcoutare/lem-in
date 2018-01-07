/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elem_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:20:38 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/25 17:24:24 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void				free_one(t_list *list)
{
	free(list->content);
	free(list);
}

void				free_elem(t_list **list, t_list *elem)
{
	t_list			*tmp;
	t_list			*tmp2;

	if (*list == elem)
	{
		tmp = (*list)->next;
		free_one(*list);
		*list = tmp;
		return ;
	}
	tmp = (*list)->next;
	while (tmp->next)
	{
		if (tmp == elem)
		{
			if (tmp->next == NULL)
				tmp2->next = NULL;
			else
				tmp2->next = tmp2->next->next;
			free_one(tmp);
		}
		tmp2 = tmp;
		tmp = tmp->next;
	}
}
