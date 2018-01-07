/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 22:35:28 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/03 20:46:27 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_base(char *base)
{
	int			len;
	int			i;

	i = 0;
	len = ft_strlen(base);
	if (len < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		len = i + 1;
		while (base[len])
		{
			if (base[i] == base[len])
				return (0);
			++len;
		}
		++i;
	}
	return (1);
}

void			ft_putnbr_base(int nbr, char *base)
{
	long		div;
	long		neg;
	long		nb1;
	long		lenbase;

	nb1 = (long)nbr;
	neg = 0;
	lenbase = ft_strlen(base);
	if (check_base(base) == 0)
		return ;
	if (nb1 < 0)
	{
		neg = 1;
		nb1 = nb1 * -1;
	}
	div = 1;
	while (nb1 / div >= lenbase)
		div = div * lenbase;
	if (neg == 1)
		ft_putchar('-');
	while (div >= 1)
	{
		ft_putchar(base[nb1 / div % lenbase]);
		div = div / lenbase;
	}
}
