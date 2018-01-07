/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:34:49 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/03 18:34:50 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(int n, int fd)
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
		ft_putchar_fd('-', fd);
	while (div >= 1)
	{
		ft_putchar_fd(nb1 / div % 10 + 48, fd);
		div = div / 10;
	}
}
