/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 15:34:03 by yguzman           #+#    #+#             */
/*   Updated: 2018/01/07 17:45:43 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"

void		init_data_map(t_dm *dm)
{
	dm->nb_ant = -1;
	dm->name_room = NULL;
	dm->start = NULL;
	dm->end = NULL;
	dm->lien = NULL;
}

void		free_tab(char **buff)
{
	int		i;

	i = 0;
	while (buff[i])
	{
		free(buff[i]);
		++i;
	}
	free(buff);
}

void		free_all(t_tree *data, t_dm *data_map)
{
	t_tree	*tmp;

//	free_tab(data_map->name_room);
//	free_tab(data_map->lien);
//	free(data_map->start);
//	free(data_map->end);
	tmp = data;
	while (tmp)
	{
		free(data->name);
		free(data->branch);
		tmp = data->next;
		free(data);
	}

}

int			main(void)
{
	t_tree	*data;
	t_dm	data_map;

	data = NULL;
	init_data_map(&data_map);
	if (read_and_fill_lemin(&data, &data_map) == -1)
		return (-1);
	if (algo_lemdeux(&data, &data_map) == -1)
		return (-1);

	free_all(data, &data_map);

	return (0);
}
