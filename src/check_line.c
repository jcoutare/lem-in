/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 17:33:56 by jcoutare          #+#    #+#             */
/*   Updated: 2018/01/07 17:33:58 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			check_line(char *line)
{
	if (ft_strncmp(line, "##", 2) == 0)
	{
		if ((ft_strcmp(line, "##start") == 0) || ft_strcmp(line, "##end") == 0)
			return (1);
		return (0);
	}
	return (1);
}
