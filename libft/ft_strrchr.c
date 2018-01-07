/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:35:53 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/03 18:35:53 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strrchr(const char *s, int c)
{
	char	*buff;

	buff = NULL;
	while (*s)
	{
		if (*s == c)
			buff = (char *)s;
		s = s + 1;
	}
	if (*s == c)
		buff = (char *)s;
	return (buff);
}
