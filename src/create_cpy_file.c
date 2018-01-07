#include <stdlib.h>
#include "libft.h"
#include "lemin.h"

char			**fill_cpy_file(void)
{
	char		*line;
	char		**file;
	int			ret;
	int			i;

	line = NULL;
	file = NULL;
	i = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (check_line(line))
		{
			if ((file = realloc_tab(file, line)) == NULL)
				return (NULL);
		}
		else
			free(line);
	}
	if (ret == -1)
		return (ft_puterr_null("gnl fail in func create_cpy_file\n"));
	if (file == NULL)
		ft_puterr("empty file\n");
	return (file);
}

char			**create_cpy_file(void)
{
	return (fill_cpy_file());
}
