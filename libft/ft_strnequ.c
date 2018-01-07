/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:35:44 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/03 18:35:45 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_strnequ(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0 || (s1 == NULL && s2 == NULL))
		return (1);
	if (s1 == NULL || s2 == NULL)
		return (0);
	while ((i < n - 1) && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return (0);
		++i;
	}
	if (s1[i] != s2[i])
		return (0);
	return (1);
}
