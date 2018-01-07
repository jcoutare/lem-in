/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_data1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 17:37:08 by jcoutare          #+#    #+#             */
/*   Updated: 2018/01/07 17:41:28 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdlib.h>
#include "libft.h"

int				search_nb_ant_start_end(char **file)
{
	int			i;

	i = 0;
	while (file[0][i])
	{
		if (!ft_isdigit(file[0][i]))
			return (ft_puterr("Bad Number ant\n"));
		++i;
	}
	if ((i = ft_atoi(file[0])) < 1)
		return (ft_puterr("Bad Number ant\n"));
	free(file[0]);
	return (i);
}

int				check_format_lien_next(char *str, t_dm *data_map, int i)
{
	int			j;

	j = 0;
	if (check_line_lien(str, data_map, i) == 0)
		return (0);
	while (data_map->name_room && data_map->name_room[j])
	{
		if ((!ft_strncmp(str, data_map->name_room[j], i)))
			if (check_line_lien(str, data_map, i) == 0)
				return (0);
		++j;
	}
	if (ft_isspace(str[i]))
		return (-1);
	return (0);
}

int				check_format_lien(char *str, t_dm *data_map)
{
	int			i;
	int			check;
	int			ret;

	i = 0;
	check = 0;
	if (data_map->start == NULL || data_map->end == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '-')
		{
			check = 1;
			if ((!ft_strncmp(str, data_map->start, i)) ||
					(!ft_strncmp(str, data_map->end, i)))
				return (0);
			if ((ret = check_format_lien_next(str, data_map, i)) == -1)
				return (-1);
			if (ret == 0)
				return (0);
		}
		++i;
	}
	return (check != 1 ? -3 : -2);
}

int				search_name_room_next(t_dm *data_map, char **file,
									int *i, int ret)
{
	if (file[*i][0] == 'L')
	{
		ft_puterr(file[*i]);
		ft_puterr("\n");
		return (ft_puterr("wrong char in room name : \'L\' _|\n"));
	}
	else if (ft_strcmp(file[*i - 1], "##start") == 0)
		data_map->start = file[*i];
	else if (ft_strcmp(file[*i - 1], "##end") == 0)
		data_map->end = file[*i];
	else if ((ret = check_name(file[*i], data_map->name_room)) == 0)
	{
		if ((data_map->name_room =
			realloc_tab(data_map->name_room, file[*i])) == NULL)
			return (-1);
	}
	if (ret == -1)
	{
		ft_puterr(file[*i]);
		ft_puterr("\n");
		return (ft_puterr("This room exist\n"));
	}
	return (0);
}

int				search_name_room(t_dm *data_map, char **file, int *i)
{
	int			ret;

	ret = -2;
	while (file[*i] && (check_format_lien(file[*i], data_map)
				<= -1) && (check_format_room(file[*i]) == 0))
	{
		if (ft_strcmp(file[*i], "##start") != 0 &&
				ft_strcmp(file[*i], "##end") != 0)
		{
			if (search_name_room_next(data_map, file, i, ret) == -1)
				return (-1);
		}
		++*i;
	}
	return (0);
}
