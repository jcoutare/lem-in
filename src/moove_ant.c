/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 17:16:41 by jcoutare          #+#    #+#             */
/*   Updated: 2018/01/07 17:33:25 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

void			lem_in_print(t_room *room)
{
	ft_putstr("f(");
	ft_putnbr(room->fourmi);
	ft_putstr(") : (");
	ft_putchar(room->name[0]);
	ft_putstr(")->(");
	ft_putchar(room->next->name[0]);
	ft_putendl(")");
}

int				lance(t_room *room, t_dm *data_map)
{
	if (room->next)
		lance(room->next, data_map);
	if (room->fourmi != 0 && room->next != NULL)
	{
		lem_in_print(room);
		room->next->fourmi = room->fourmi;
		room->fourmi = 0;
		return (1);
	}
	return (0);
}

int				nb_coup_total(t_dm *data_map, int *lol, int *xd)
{
	int			value;
	int			i;
	int			j;

	i = 0;
	j = 0;
	value = xd[i];
	while (i < ft_list_size_t(data_map->chemin))
	{
		if (xd[i] > value)
		{
			value = xd[i];
			j = i;
		}
		i++;
	}
	return (value + lol[j] - 1);
}

void			print_round(t_dm *data_map, int *xd, int *lol, int round)
{
	ft_putstr("\n[ROUND ");
	ft_putnbr(nb_coup_total(data_map, lol, xd) - round);
	ft_putendl("]");
}

void			launch_the_nukes(t_dm *data_map, int *xd, int *lol, int i)
{
	t_truc		*chemin;
	t_room		*room;
	int			round;
	int			ant;

	ant = 1;
	round = nb_coup_total(data_map, lol, xd);
	while (round--)
	{
		chemin = data_map->chemin;
		i = 0;
		print_round(data_map, xd, lol, round);
		while (chemin)
		{
			if (xd[i] > 0)
			{
				room = chemin->room;
				if (ant <= data_map->nb_ant)
					room->fourmi = ant++;
				lance(room, data_map);
			}
			i++;
			chemin = chemin->next;
		}
	}
}
