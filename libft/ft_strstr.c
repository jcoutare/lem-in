/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:35:57 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/03 18:41:20 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strstr(const char *meule_de_foin, const char *aiguille)
{
	int		i;
	int		j;
	int		save;

	i = 0;
	if (aiguille[0] == 0)
		return ((char *)meule_de_foin);
	while (meule_de_foin[i])
	{
		j = 0;
		if (meule_de_foin[i] == aiguille[j])
		{
			save = i;
			while (meule_de_foin[save] && aiguille[j] &&
					meule_de_foin[save] == aiguille[j])
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
