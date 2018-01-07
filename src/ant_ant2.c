/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_ant2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:17:50 by jcoutare          #+#    #+#             */
/*   Updated: 2018/01/07 18:36:51 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"
void	loop_list(t_dm *data_map, t_truc *tmp_c, t_truc *main_c, t_room *main_room)
{
	t_room *tmp_r;
	int			smaller;

	smaller = ft_list_size_r(main_c->room);
	while (tmp_c)
	{
		set_cancer_2(smaller, tmp_c, main_c);
		tmp_r = tmp_c->room;
		while (tmp_r)
		{
			if (ft_strcmp(tmp_r->name, main_room->name) == 0
				&& (ft_strcmp(tmp_r->name, data_map->end) != 0 &&
					ft_strcmp(tmp_r->name, data_map->start) != 0))
				set_cancer(tmp_c, main_c);
			tmp_r = tmp_r->next;
		}
		tmp_c = tmp_c->next;
	}
}

void	set_cancer_2(int smaller, t_truc *tmp_c, t_truc *main_c)
{
	if (smaller < ft_list_size_r(tmp_c->room))
		tmp_c->cancer = 1;
	else if (smaller > ft_list_size_r(tmp_c->room))
		main_c->cancer = 1;
}

void	set_cancer(t_truc *tmp_c, t_truc *main_c)
{
	if (ft_list_size_r(tmp_c->room) > ft_list_size_r(main_c->room))
		tmp_c->cancer = 1;
	else
		main_c->cancer = 1;
}
