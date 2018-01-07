/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 17:36:50 by jcoutare          #+#    #+#             */
/*   Updated: 2018/01/07 17:42:43 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "lemin.h"

int				find_start(t_tree **data, t_dm *data_map)
{
	while (*data)
	{
		if (ft_strcmp(data_map->start, (*data)->name) == 0)
			return (1);
		*data = (*data)->next;
	}
	return (-1);
}

t_tree			*create_maillon(char *name, int what)
{
	t_tree		*new;

	if ((new = malloc(sizeof(t_tree))) == NULL)
		return (NULL);
	new->name = name;
	new->next = NULL;
	new->what = what;
	new->branch = NULL;
	new->validroom = 0;
	return (new);
}

void			push_maillon(t_tree **data, t_tree *elem)
{
	elem->next = *data;
	*data = elem;
}

int				realloc_branch(t_tree *src, t_tree *dest)
{
	int			i;
	t_tree		**tmp;

	if (dest->branch == NULL)
	{
		if ((dest->branch = malloc(sizeof(t_tree *) * 2)) == NULL)
			return (-1);
		dest->branch[0] = src;
		dest->branch[1] = NULL;
		return (0);
	}
	i = 0;
	while (dest->branch[i])
		++i;
	if ((tmp = malloc(sizeof(t_tree *) * (i + 2))) == NULL)
		return (-1);
	ft_memcpy(tmp, dest->branch, ((i + 1) * (sizeof(t_tree *))));
	tmp[i] = src;
	tmp[i + 1] = NULL;
	dest->branch = tmp;
	return (0);
}
