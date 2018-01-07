/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:39:25 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/03 20:39:43 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*t1;
	unsigned char	*t2;

	t1 = (unsigned char*)s1;
	t2 = (unsigned char*)s2;
	while (*t1 && *t1 == *t2 && n--)
	{
		++t1;
		++t2;
	}
	if (n == 0)
	{
		--t1;
		--t2;
	}
	return (*t1 - *t2);
}
