/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_ant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:28:14 by jcoutare          #+#    #+#             */
/*   Updated: 2018/01/07 18:34:28 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"
#include <stdlib.h>

void			check_list(t_dm *data_map)
{
	t_truc		*main_c;
	t_truc		*tmp_c;
	t_room		*main_room;
	t_room		*tmp_r;
	int			smaller;

	main_c = data_map->chemin;
	while (main_c->next)
	{
		smaller = ft_list_size_r(main_c->room);
		main_room = main_c->room;
		while (main_room)
		{
			tmp_c = main_c->next;
			loop_list(data_map, tmp_c, main_c, main_room);
			main_room = main_room->next;
		}
		main_c = main_c->next;
	}
}

int				*create_xd(t_dm *data_map)
{
	int			*xd;
	int			i;

	i = 0;
	if (!(xd = malloc(sizeof(int) * ft_list_size_t(data_map->chemin))))
		return (NULL);
	while (i < ft_list_size_t(data_map->chemin))
	{
		xd[i] = 0;
		i++;
	}
	return (xd);
}

int				*fill_ant_send(t_dm *data_map, int *lol)
{
	int			*xd;
	int			i;
	int			n;
	int			ant;

	ant = data_map->nb_ant;
	n = 0;
	xd = create_xd(data_map);
	while (ant)
	{
		i = 0;
		while (i < ft_list_size_t(data_map->chemin))
		{
			if (lol[i] != -1)
			{
				xd[i]++;
				if (--ant == 0)
					return (xd);
			}
			i++;
		}
	}
	return (xd);
}

int				*fill_len_path(t_dm *data_map)
{
	t_truc		*tmp;
	int			*jecodeaveclecul;
	int			i;
	int			count;

	i = 0;
	count = 0;
	tmp = data_map->chemin;
	if (!(jecodeaveclecul = malloc(sizeof(int) * ft_list_size_t(tmp))))
		return (NULL);
	while (tmp)
	{
		if (tmp->cancer == 0)
			jecodeaveclecul[i] = ft_list_size_r(tmp->room) - 1;
		else
			jecodeaveclecul[i] = -1;
		i++;
		tmp = tmp->next;
	}
	return (jecodeaveclecul);
}

int				ant_ant(t_dm *data_map)
{
	int			*len_path;
	int			*ant_to_send;

	check_list(data_map);
	if (!(len_path = fill_len_path(data_map)))
		return (-1);
	if (!(ant_to_send = fill_ant_send(data_map, len_path)))
		return (-1);
	launch_the_nukes(data_map, len_path, ant_to_send, 0);
	return (1);
}
