#include "lemin.h"
#include "libft.h"
#include <unistd.h>

t_room		*lst_copy(t_room **begin_list)
{
	t_room	*new;
	t_room	*list;

	list = *begin_list;
	new = NULL;
	while (list)
	{
		if (!(l_push_back(&new, list->name)))
			return (NULL);
		list = list->next;
	}
	return (new);
}
