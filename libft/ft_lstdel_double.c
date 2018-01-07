/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:55:19 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/03 18:02:39 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			ft_lstdel_double(t_list **alst, t_list *del)
{
	t_list		*tmp;

	tmp = *alst;
	while (tmp != del)
		tmp = tmp->next;
	if (tmp->prev == NULL && tmp->next == NULL)
		*alst = NULL;
	else if (tmp->prev == NULL)
	{
		tmp = tmp->next;
		tmp->prev = NULL;
		*alst = tmp;
	}
	else if (tmp->next == NULL)
	{
		tmp = tmp->prev;
		tmp->next = NULL;
	}
	else
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		tmp->prev = NULL;
		tmp->next = NULL;
	}
}
