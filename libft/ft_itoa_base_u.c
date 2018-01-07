/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 13:12:02 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/05 18:50:40 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void						fill_buffu(char *buff, char *base,
										unsigned long long int value,
										unsigned long long int div)
{
	int						size_b;
	int						i;

	size_b = ft_strlen(base);
	i = 0;
	while (div > 0)
	{
		buff[i] = base[value / div % size_b];
		++i;
		div = div / size_b;
	}
	buff[i] = 0;
}

char						*ft_itoa_base_u(unsigned long long int value,
											char *base)
{
	char					*buff;
	int						len_buff;
	unsigned long long int	size_b;
	unsigned long long int	div;

	len_buff = 0;
	size_b = ft_strlen(base);
	div = 1;
	while (value / div >= size_b)
	{
		div = div * size_b;
		++len_buff;
	}
	if ((buff = malloc(sizeof(char) * (len_buff + 2))) == NULL)
		return (NULL);
	fill_buffu(buff, base, value, div);
	return (buff);
}
