/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_cpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 17:35:58 by jcoutare          #+#    #+#             */
/*   Updated: 2018/01/07 17:35:59 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"
#include <unistd.h>

t_room		*lst_copy(t_room **begin_list)
{
	t_room	*new;
	t_room	*list;

	list = *begin_list;
	new = NULL;
	while (list)
	{
		if (!(l_push_back(&new, list->name)))
			return (NULL);
		list = list->next;
	}
	return (new);
}
