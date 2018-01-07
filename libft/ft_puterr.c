/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 20:55:12 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/25 20:05:22 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

int			ft_puterr(char *str)
{
	write(2, str, ft_strlen(str));
	return (-1);
}

void		*ft_puterr_null(char *str)
{
	write(2, str, ft_strlen(str));
	return (NULL);
}
