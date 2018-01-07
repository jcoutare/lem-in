/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:36:03 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/03 18:42:33 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_new(char const *s)
{
	int		len_new;
	int		i;
	int		save;

	i = 0;
	len_new = 0;
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
		++i;
	while (s[i])
	{
		if (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
		{
			save = i;
			while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
				++i;
			if (s[i] == 0)
				break ;
			i = save;
		}
		++len_new;
		++i;
	}
	return (len_new);
}

static int	copy_new(char const *s, char *new)
{
	int		len_new;
	int		i;
	int		j;
	int		save;

	i = 0;
	j = 0;
	len_new = 0;
	while (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
		++i;
	while (s[i])
	{
		if (s[i] == '\n' || s[i] == ' ' || s[i] == '\t')
		{
			save = i;
			while (s[save] == '\n' || s[save] == ' ' || s[save] == '\t')
				++save;
			if (s[save] == 0)
				break ;
		}
		new[j++] = s[i++];
		++len_new;
	}
	new[j] = 0;
	return (len_new);
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	size_t	len_new;

	if (s == NULL)
		return (NULL);
	len_new = count_new(s);
	if ((new = malloc(sizeof(char) * (len_new + 1))) == NULL)
		return (NULL);
	copy_new(s, new);
	return (new);
}
