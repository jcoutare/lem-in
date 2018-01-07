/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:35:47 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/03 21:04:50 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	if ((new = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (i < size + 1)
	{
		new[i] = 0;
		++i;
	}
	return (new);
}
