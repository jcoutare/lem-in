/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocfake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:27:29 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/25 17:27:30 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void				*ft_reallocfake(void *ptr, size_t size_ptr, size_t size)
{
	void			*new;

	if (ptr == NULL)
	{
		if ((ptr = malloc(sizeof(char) * size)) == NULL)
			return (NULL);
		ft_bzero(ptr, size);
		return (ptr);
	}
	if ((new = malloc(sizeof(char) * (size_ptr + size))) == NULL)
		return (NULL);
	ft_bzero(new, size_ptr + size);
	ft_memcpy(new, ptr, size_ptr);
	free(ptr);
	return (new);
}
