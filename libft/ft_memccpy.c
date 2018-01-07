/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:34:12 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/03 18:34:13 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*buff;
	char	*buff1;
	size_t	i;

	buff = (char *)src;
	buff1 = (char *)dest;
	i = 0;
	while (i < n)
	{
		++i;
		*buff1 = *buff;
		if (*buff == c)
			return ((void *)(buff1 + 1));
		buff1 = buff1 + 1;
		buff = buff + 1;
	}
	return (NULL);
}
