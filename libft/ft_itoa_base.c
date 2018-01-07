/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 15:30:01 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/06 17:36:18 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

void						fill_buff(char *buff, char *base,
										long long int value, long long int div)
{
	int						size_b;
	int						i;

	size_b = ft_strlen(base);
	i = 0;
	if (buff[0] == '-')
		++i;
	while (div > 0)
	{
		buff[i] = base[value / div % size_b];
		++i;
		div = div / size_b;
	}
	buff[i] = 0;
}

void						check_neg(long long int *value,
										int *neg, int *len_buff)
{
	if (*value < 0)
	{
		*neg = 1;
		*value = *value * -1;
		++*len_buff;
	}
}

void						put_neg(char *buff, int neg, int len_buff)
{
	ft_memset(buff, 0, len_buff);
	if (neg == 1)
		buff[0] = '-';
}

char						*particulier(long long int value)
{
	if (value == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	else
		return (NULL);
}

char						*ft_itoa_base(long long int value, char *base)
{
	char					*buff;
	int						len_buff;
	int						neg;
	long long int			size_b;
	long long int			div;

	if ((buff = particulier(value)) != NULL)
		return (buff);
	neg = 0;
	len_buff = 0;
	size_b = ft_strlen(base);
	div = 1;
	check_neg(&value, &neg, &len_buff);
	while (value / div >= size_b)
	{
		div = div * size_b;
		++len_buff;
	}
	if ((buff = malloc(sizeof(char) * (len_buff + 1))) == NULL)
		return (NULL);
	ft_memset(buff, 0, len_buff + 1);
	put_neg(buff, neg, len_buff);
	fill_buff(buff, base, value, div);
	return (buff);
}
