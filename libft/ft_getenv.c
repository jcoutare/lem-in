/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:21:16 by yguzman           #+#    #+#             */
/*   Updated: 2017/09/27 16:21:18 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_getenv(char *name, t_list *my_env)
{
	if (!my_env)
		return (NULL);
	while (my_env)
	{
		if (ft_strncmp(name, (char *)(my_env->content), ft_strlen(name)) == 0)
			return ((char *)(my_env->content) + ft_strlen(name));
		my_env = my_env->next;
	}
	return (NULL);
}
