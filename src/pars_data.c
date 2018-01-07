/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 17:43:05 by jcoutare          #+#    #+#             */
/*   Updated: 2018/01/07 17:45:20 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "lemin.h"

int			check_line_lien(char *str, t_dm *data_map, int i)
{
	int		j;
	int		size;

	str = str + i + 1;
	size = ft_strlen(str);
	if ((!ft_strncmp(str, data_map->start, size)) ||
			(!ft_strncmp(str, data_map->end, size)))
		return (0);
	j = 0;
	while (data_map->name_room && data_map->name_room[j])
	{
		if ((!ft_strncmp(str, data_map->name_room[j], size)))
			return (0);
		++j;
	}
	return (-1);
}

int			check_format_room(char *str)
{
	int		i;
	int		j;

	if ((ft_strcmp(str, "##start") == 0) || ft_strcmp(str, "##end") == 0)
		return (0);
	i = 0;
	while (str[i] && (!ft_isspace(str[i])))
		++i;
	j = 0;
	while (j < 2)
	{
		if (!ft_isspace(str[i]))
			return (-1);
		++i;
		while (str[i] && (!ft_isspace(str[i])))
		{
			if (!ft_isdigit(str[i]))
				return (-1);
			++i;
		}
		++j;
	}
	return (0);
}

int			check_name(char *str, char **tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] && (ft_isspace(str[j]) != 1))
		++j;
	while (tab && tab[i])
	{
		if (ft_strncmp(str, tab[i], j) == 0)
			return (-1);
		++i;
	}
	return (0);
}

int			search_lien(t_dm *data_map, char **file, int i)
{
	int		ret;

	while (file[i])
	{
		if ((ret = check_format_lien(file[i], data_map)) <= -1)
		{
			ft_puterr(file[i]);
			ft_puterr("\n");
			if (ret == -1)
				return (ft_puterr("Wrong char during link creation _|\n"));
			else if (ret == -2)
				return (ft_puterr("Wrong char during link creation _|\n"));
			else if (ret == -3)
				return (ft_puterr("Wrong char [name-name] in l_creation _|\n"));
		}
		if ((data_map->lien = realloc_tab(data_map->lien, file[i])) == NULL)
			return (-1);
		++i;
	}
	return (0);
}

int			pars_data(char **file, t_dm *data_map)
{
	int		i;
	char	**buf;

	i = 1;
	buf = file;
	if ((data_map->nb_ant = search_nb_ant_start_end(file)) == -1)
		return (-1);
	if (search_name_room(data_map, file, &i) == -1)
		return (-1);
	if (data_map->start == NULL)
		return (ft_puterr("Create room start\n"));
	else if (data_map->end == NULL)
		return (ft_puterr("Create room end\n"));
	if (search_lien(data_map, file, i) == -1)
		return (-1);
	free(buf);
	return (0);
}
