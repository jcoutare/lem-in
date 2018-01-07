/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:35:49 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/03 18:40:43 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strnstr(const char *meule_de_foin, const char *aiguille,
						size_t len)
{
	size_t	i;
	int		j;
	int		save;

	i = 0;
	if (aiguille[0] == 0)
		return ((char *)meule_de_foin);
	while (meule_de_foin[i] && i < len)
	{
		j = 0;
		if (meule_de_foin[i] == aiguille[j])
		{
			save = i;
			while (meule_de_foin[save] && aiguille[j] &&
					meule_de_foin[save] == aiguille[j] && i + (save - i) < len)
			{
				++save;
				++j;
			}
			if (aiguille[j] == 0)
				return ((char *)&(meule_de_foin[i]));
		}
		i += 1;
	}
	return (NULL);
}
