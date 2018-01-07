/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 17:36:24 by jcoutare          #+#    #+#             */
/*   Updated: 2018/01/07 17:36:26 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "libft.h"

int				read_and_fill_lemin(t_tree **data, t_dm *data_map)
{
	char		**file;
	int			i;

	i = 0;
	if ((file = create_cpy_file()) == NULL)
		return (-1);
	while (file[i])
	{
		ft_putendl(file[i]);
		i++;
	}
	if (pars_data(file, data_map) == -1)
		return (-1);
	if (fill_data(data, data_map) == -1)
		return (-1);
	return (0);
}
