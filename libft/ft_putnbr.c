/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 19:28:53 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/04 17:04:08 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr(int n)
{
	int			div;
	int			neg;
	long		nb1;

	nb1 = (long)n;
	neg = 0;
	if (nb1 < 0)
	{
		neg = 1;
		nb1 = nb1 * -1;
	}
	div = 1;
	while (nb1 / div > 9)
		div = div * 10;
	if (neg == 1)
		ft_putchar('-');
	while (div >= 1)
	{
		ft_putchar(nb1 / div % 10 + 48);
		div = div / 10;
	}
}
