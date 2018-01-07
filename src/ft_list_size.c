/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoutare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 09:38:50 by jcoutare          #+#    #+#             */
/*   Updated: 2017/04/26 17:31:21 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

int		ft_list_size_t(t_truc *begin_list)
{
	t_truc	*list;
	int	i;

	list = begin_list;
	i = 0;
	if (list == NULL)
		return (i);
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int		ft_list_size_r(t_room *begin_list)
{
	t_room	*list;
	int	i;

	list = begin_list;
	i = 0;
	if (list == NULL)
		return (i);
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
