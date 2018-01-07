#include "libft.h"

int			check_line(char *line)
{
	if (ft_strncmp(line, "##", 2) == 0)
	{
		if ((ft_strcmp(line, "##start") == 0) || ft_strcmp(line, "##end") == 0)
			return (1);
		return (0);
	}
	return (1);
}
