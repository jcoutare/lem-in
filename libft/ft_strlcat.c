/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 20:04:44 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/10 19:23:45 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t					ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t				len;
	int					j;
	int					save;
	size_t				save_1;
	int					save_2;

	j = ft_strlen(dest);
	save_1 = ft_strlen(dest);
	save_2 = ft_strlen(src);
	save = j;
	len = 0;
	while (src[len] && (len + save_1) < size - 1)
	{
		dest[j] = src[len];
		++j;
		++len;
	}
	if (j != save)
		dest[j] = '\0';
	if (save_1 > size)
		return (save_2 + size);
	return (save_1 + save_2);
}
