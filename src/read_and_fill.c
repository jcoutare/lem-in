#include <stdlib.h>
#include "lemin.h"
#include "libft.h"

int				read_and_fill_lemin(t_tree **data, t_dm *data_map)
{
	char		**file;
	int			i;

	i = 0;
	if ((file = create_cpy_file()) == NULL)
		return (-1);
	while (file[i])
	{
		ft_putendl(file[i]);
		i++;
	}
	if (pars_data(file, data_map) == -1)
		return (-1);
	if (fill_data(data, data_map) == -1)
		return (-1);
	return (0);
}
