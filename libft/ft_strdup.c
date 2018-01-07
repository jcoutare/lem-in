/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 12:08:48 by yguzman           #+#    #+#             */
/*   Updated: 2016/07/18 18:44:34 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strdup(const char *src)
{
	char		*dest;

	if ((dest = malloc(sizeof(char) * (ft_strlen(src) + 1))) == NULL)
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}
