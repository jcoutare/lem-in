/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:03:25 by jcoutare          #+#    #+#             */
/*   Updated: 2017/12/28 18:33:36 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

void			check_branch(t_tree *data, t_dm *data_map, char *prev, int *i)
{
	int			j;

	j = -1;
	while (j != *i)
	{ j = *i;
		if (data->branch[*i])
			if (ft_strcmp(data->branch[*i]->name, data_map->start) == 0)
				++*i;
		if (prev != NULL)
		{
			if (data->branch[*i])
				if (ft_strcmp(prev, data->branch[*i]->name) == 0)
					++*i;
		}
	}
}

int				la_liste(t_dm *data_map, t_tree *data)
{
	t_truc		*tmp;
	t_truc		*new;

	if (l_push_back(&data_map->room, data->name) == -1)
		return (-1);
	if ((new = malloc(sizeof(t_truc))) == NULL)
		return (-1);
	if ((new->room = lst_copy(&data_map->room)) == NULL)
		return (-1);
	new->next = NULL;
	if (data_map->chemin == NULL)
	{
		data_map->chemin = new;
		return (0);
	}
	tmp = data_map->chemin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	lst_remove_last(&data_map->room);
	return (0);
}

int				pas_propre(t_tree *data, t_dm *data_map, char *prev, int *i)
{
	t_room		*tmp;

	++*i;
	if (data->branch[*i])
	{
		check_branch(data, data_map, prev, i);
		if (data->branch[*i])
		{
			tmp = data_map->room;
			while (tmp->next)
				tmp = tmp->next;
			if (!(ft_strcmp(data->name, tmp->name) == 0))
				if (l_push_back(&(data_map->room), data->name) == -1)
					return (-1);
			if (get_path(data->branch[*i], data_map, data->name, 0) == -1)
				return (-1);
			lst_remove_last(&data_map->room);
		}
	}
	return (0);
}

int				get_path(t_tree *data, t_dm *data_map, char *prev, int i)
{
	if (ft_strcmp(data->name, data_map->end) != 0)
	{
		check_branch(data, data_map, prev, &i);
		if (data->branch[i])
		{
			if (l_push_back(&(data_map->room), data->name) == -1)
				return (-1);
			if (get_path(data->branch[i], data_map, data->name, 0) == -1)
				return (-1);
			lst_remove_last(&data_map->room);
		}
	}
	if (ft_strcmp(data->name, data_map->end) != 0)
	{
		while (data->branch[i])
			if (pas_propre(data, data_map, prev, &i) == -1)
				return (-1);
	}
	else
		if (la_liste(data_map, data) == -1)
			return (-1);
	return (0);
}

int				algo_lemdeux(t_tree **data, t_dm *data_map)
{
	int			i;

	i = 0;
	data_map->room = NULL;
	data_map->chemin = NULL;
	if (find_start(data, data_map) == -1)
		return (ft_puterr("no start\n"));
	if (get_path(*data, data_map, NULL, 0) == -1)
	  return (-1);
	if (ant_ant(data_map) == -1)
		return (-1);
	return (1);
}
