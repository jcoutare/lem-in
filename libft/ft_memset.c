/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:34:30 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/03 18:34:31 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memset(void *s, int c, size_t n)
{
	char	*buff;
	size_t	i;

	i = 0;
	buff = (char *)s;
	while (i < n)
	{
		*buff = c;
		++i;
		buff = buff + 1;
	}
	return (s);
}
