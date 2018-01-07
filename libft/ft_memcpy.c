/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:34:22 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/03 18:34:23 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*buff;
	char	*buff1;
	size_t	i;

	buff = (char *)src;
	buff1 = (char *)dest;
	i = 0;
	while (i < n)
	{
		*buff1 = *buff;
		buff = buff + 1;
		buff1 = buff1 + 1;
		++i;
	}
	return (dest);
}
