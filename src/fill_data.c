/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 17:34:27 by jcoutare          #+#    #+#             */
/*   Updated: 2018/01/07 17:34:29 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "lemin.h"

int			push_branch(t_tree *data, t_tree *elem)
{
	if (realloc_branch(data, elem) == -1)
		return (-1);
	if (realloc_branch(elem, data) == -1)
		return (-1);
	return (0);
}

int			create_list_name_room(t_tree **data, t_dm *data_map)
{
	int		i;
	t_tree	*push;

	if ((push = create_maillon(data_map->start, 1)) == NULL)
		return (-1);
	push_maillon(data, push);
	if ((push = create_maillon(data_map->end, 2)) == NULL)
		return (-1);
	push_maillon(data, push);
	i = 0;
	while (data_map->name_room && data_map->name_room[i])
	{
		if ((push = create_maillon(data_map->name_room[i], 0)) == NULL)
			return (-1);
		push_maillon(data, push);
		++i;
	}
	free(data_map->name_room);
	return (0);
}

int			return_len_lien(char *lien)
{
	int		i;

	i = 0;
	while (lien[i] && lien[i] != '-')
		++i;
	return (i);
}

int			create_lien(t_tree **data, char *lien)
{
	t_tree	*tmp;
	t_tree	*tmp1;

	tmp = *data;
	while (tmp)
	{
		if (!ft_strncmp(tmp->name, lien, return_len_lien(lien)))
			break ;
		tmp = tmp->next;
	}
	tmp1 = *data;
	while (tmp1)
	{
		if (!ft_strncmp(tmp1->name, lien + 1 + return_len_lien(lien),
					ft_strlen(lien + 1 + return_len_lien(lien))))
			break ;
		tmp1 = tmp1->next;
	}
	if (push_branch(tmp, tmp1) == -1)
		return (-1);
	return (0);
}

int			fill_data(t_tree **data, t_dm *data_map)
{
	int		i;

	if (create_list_name_room(data, data_map) == -1)
		return (-1);
	i = 0;
	while (data_map->lien[i] != NULL)
	{
		if (create_lien(data, data_map->lien[i]) == -1)
			return (-1);
		free(data_map->lien[i]);
		++i;
	}
	free(data_map->lien);
	return (0);
}
