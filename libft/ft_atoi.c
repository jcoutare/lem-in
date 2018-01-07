/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 11:02:47 by yguzman           #+#    #+#             */
/*   Updated: 2016/07/18 18:50:45 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		parser_atoi(const char *str, int i)
{
	if (str[i] == '-')
		return (1);
	if (str[i] == '+')
		return (2);
	return (0);
}

static int		parser_space(const char *str)
{
	int			i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' ||
					str[i] == '\r' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f'))
		++i;
	return (i);
}

int				ft_atoi(const char *nptr)
{
	int			i;
	int			nb;
	int			neg;

	i = parser_space(nptr);
	neg = parser_atoi(nptr, i);
	nb = 0;
	if (neg == 1 || neg == 2)
		++i;
	if (neg == 1)
	{
		while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
		{
			nb = nb * 10 + ((nptr[i] - 48));
			++i;
		}
		return (-nb);
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + ((nptr[i] - 48));
		++i;
	}
	return (nb);
}

int				ft_atoi_oct(char *str)
{
	int			i;
	int			nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		nb = (nb + (str[i] - '0'));
		if (str[i + 1])
			nb = nb * 8;
		++i;
	}
	return (nb);
}
