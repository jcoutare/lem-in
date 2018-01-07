/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:34:27 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/04 21:13:12 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*buff;
	char		*buff1;

	buff = (char *)dest;
	buff1 = (char *)src;
	i = 0;
	if (buff < buff1)
		while (i < n)
		{
			buff[i] = buff1[i];
			++i;
		}
	else if (buff > buff1)
	{
		buff += n - 1;
		buff1 += n - 1;
		while (n--)
			*buff-- = *buff1--;
	}
	return (dest);
}
