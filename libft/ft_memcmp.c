/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:34:19 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/04 17:31:59 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*buff;
	unsigned char	*buff1;
	size_t			i;

	buff = (unsigned char *)s1;
	buff1 = (unsigned char *)s2;
	i = 0;
	if (s1 == NULL)
		return (0);
	while (i < n)
	{
		if (buff[i] != buff1[i])
			return (buff[i] - buff1[i]);
		++i;
	}
	return (0);
}
