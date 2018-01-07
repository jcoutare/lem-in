/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:34:15 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/03 18:36:58 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*buff;
	size_t			i;

	i = 0;
	buff = (unsigned char *)s;
	while (i < n)
	{
		if (*buff == (unsigned char)c)
			return (buff);
		buff = buff + 1;
		++i;
	}
	return (NULL);
}
