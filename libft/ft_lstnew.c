/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:33:41 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/03 21:15:52 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if ((new = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content_size = 0;
		new->content = 0;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->content_size = content_size;
		if ((new->content = malloc(sizeof(char) * content_size)) == NULL)
			return (NULL);
		ft_memcpy(new->content, content, content_size);
		new->next = NULL;
		new->prev = NULL;
	}
	return (new);
}
