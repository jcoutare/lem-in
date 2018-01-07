/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:07:51 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/03 18:29:41 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*tmp;
	int			i;

	if (lst == NULL || f == NULL)
		return (NULL);
	i = 0;
	while (lst)
	{
		if (i++ == 0)
		{
			tmp = f(lst);
			new = tmp;
		}
		lst = lst->next;
		if (lst)
			tmp->next = f(lst);
		tmp = tmp->next;
	}
	tmp = NULL;
	return (new);
}
