/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:55:08 by yguzman           #+#    #+#             */
/*   Updated: 2017/04/13 18:55:11 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void			ft_lstadd_double(t_list **alst, t_list *new)
{
	if (alst == NULL || new == NULL)
		return ;
	new->prev = NULL;
	if (*alst == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*alst = new;
		return ;
	}
	new->next = *alst;
	(*alst)->prev = new;
	*alst = new;
}
