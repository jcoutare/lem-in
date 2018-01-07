/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:33:15 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/04 17:28:40 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		copy_nb(long nb1, int div, char *nb, int *i)
{
	while (div >= 1)
	{
		nb[*i] = (nb1 / div % 10 + 48);
		div = div / 10;
		++*i;
	}
}

static void		ft_nb_is_negative(long *nb1, int *neg, int *i)
{
	if (*nb1 < 0)
	{
		*neg = 1;
		*i += 1;
		*nb1 = *nb1 * -1;
	}
}

char			*ft_itoa(int n)
{
	int			div;
	int			neg;
	char		*nb;
	long		nb1;
	int			i;

	nb1 = (long)n;
	neg = 0;
	div = 1;
	i = 0;
	ft_nb_is_negative(&nb1, &neg, &i);
	while (nb1 / div > 9)
	{
		div = div * 10;
		++i;
	}
	++i;
	if ((nb = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	if (neg == 1)
		nb[i++] = '-';
	copy_nb(nb1, div, nb, &i);
	nb[i] = 0;
	return (nb);
}
