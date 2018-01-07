/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 19:41:05 by yguzman           #+#    #+#             */
/*   Updated: 2016/11/04 21:42:06 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int			skype_blank(char *str, int *i, int *word, char *c)
{
	if (*i != 0)
	{
		str[*i] = '\0';
		++*i;
		++*word;
	}
	while (str[*i] && find_char_in_str(str[*i], c))
		++*i;
	if (str[*i] == '\0')
		return (1);
	return (0);
}

static int			put_null(char *str, char *c)
{
	int				i;
	int				word;

	i = 0;
	word = 0;
	skype_blank(str, &i, &word, c);
	if (str[i] == '\0')
		return (word);
	i = ((i == 0) ? (i + 1) : i);
	while (1)
	{
		if ((find_char_in_str(str[i - 1], c) == 0 &&
				find_char_in_str(str[i], c)) || str[i] == '\0')
		{
			if (str[i] == '\0')
				return (++word);
			if (skype_blank(str, &i, &word, c) == 1)
				return (word);
		}
		else
			++i;
	}
	return (0);
}

static void			skype_turfu(char **str, char *c)
{
	while (**str && find_char_in_str(**str, c))
		++*str;
}

static char			*ft_strdup_modif(char const *str, char *c)
{
	char			*new;
	int				i;

	i = 0;
	while (find_char_in_str(str[i], c))
		++i;
	if ((new = malloc(sizeof(char) * (ft_strlen(str) - i + 1))) == NULL)
		return (NULL);
	ft_strcpy(new, str + i);
	return (new);
}

char				**ft_strsplit(char const *str, char *c)
{
	char			*dest;
	int				word;
	char			**tab;
	int				i;

	tab = 0;
	if (str == NULL)
		return (NULL);
	i = 0;
	if ((dest = ft_strdup_modif(str, c)) == 0)
		return (0);
	word = put_null(dest, c);
	if ((tab = malloc(sizeof(char *) * (word + 1))) == 0)
		return (0);
	while (word)
	{
		skype_turfu(&dest, c);
		tab[i] = dest;
		while (*dest)
			++dest;
		++i;
		++dest;
		--word;
	}
	return ((tab[i] = 0) ? tab : tab);
}
