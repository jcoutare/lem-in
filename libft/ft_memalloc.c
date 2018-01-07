/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:33:27 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/03 21:02:21 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*new;
	char	*buff;
	size_t	i;

	i = 0;
	if ((new = malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	buff = (char *)new;
	while (i < size)
	{
		++i;
		*buff = 0;
		buff = buff + 1;
	}
	return (new);
}
