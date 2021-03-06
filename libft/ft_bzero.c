/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:32:42 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/03 18:32:43 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		ft_bzero(void *s, size_t n)
{
	char	*buff;
	size_t	i;

	buff = (char *)s;
	i = 0;
	while (i < n)
	{
		++i;
		*buff = 0;
		buff = buff + 1;
	}
}
