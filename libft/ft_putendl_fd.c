/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:34:43 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/04 17:10:57 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void			ft_putendl_fd(char const *str, int fd)
{
	write(fd, (const void *)str, ft_strlen(str));
	write(fd, (const void *)"\n", 1);
}
