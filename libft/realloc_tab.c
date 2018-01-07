#include <stdlib.h>
#include "libft.h"

char			**cpy_tab(char **tab, char **buff)
{
	int			i;

	i = 0;
	while (tab[i])
	{
		buff[i] = tab[i];
		++i;
	}
	buff[i] = NULL;
	free(tab);
	return (buff);
}

char			**realloc_tab(char **tab, char *str)
{
	char		**buff;
	int			i;

	if (tab == NULL)
	{
		if ((buff = malloc(sizeof(char *) * 2)) == NULL)
			return (ft_puterr_null("malloc fail in realloc_tab\n"));
		buff[0] = str;
		buff[1] = NULL;
	}
	else
	{
		i = 0;
		while (tab[i])
			++i;
		if ((buff = malloc(sizeof(char *) * (i + 2))) == NULL)
			return (ft_puterr_null("malloc fail in realloc_tab\n"));
		buff = cpy_tab(tab, buff);
		buff[i] = str;
		buff[i + 1] = NULL;
	}
	return (buff);
}
