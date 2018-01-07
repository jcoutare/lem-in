#include "lemin.h"
#include "libft.h"
#include <stdlib.h>

void		check_list(t_dm *data_map)
{
  t_truc *main_c;
  t_truc *tmp_c;
  t_room *main_room;
  t_room *tmp_r;  
  int	  smaller;

  
  main_c = data_map->chemin;
  while (main_c->next)
    {
      smaller = ft_list_size_r(main_c->room);
      main_room = main_c->room;
      while (main_room)
	{
	  tmp_c = main_c->next;
	  while (tmp_c)
	    {
	      if (smaller < ft_list_size_r(tmp_c->room))
		tmp_c->cancer = 1;
	      else if (smaller > ft_list_size_r(tmp_c->room))
		main_c->cancer = 1;
	      tmp_r = tmp_c->room;
	      while (tmp_r)
		{
		  if (ft_strcmp(tmp_r->name, main_room->name) == 0
		      && (ft_strcmp(tmp_r->name, data_map->end) != 0 &&
			  ft_strcmp(tmp_r->name, data_map->start) != 0))
		    {
		      if (ft_list_size_r(tmp_c->room) > ft_list_size_r(main_c->room))
			tmp_c->cancer = 1;
		      else
			main_c->cancer = 1;
		    }
		  tmp_r = tmp_r->next;
		}
	      tmp_c = tmp_c->next;
	    }
	  main_room = main_room->next;
	}
      main_c = main_c->next;
    }
}


int		*fill_jecodeaveclecul(t_dm *data_map)
{
  t_truc	*tmp;
  int		*jecodeaveclecul;
  int		i;
  int		count;

  i = 0;
  count = 0;
  tmp = data_map->chemin;
  if (!(jecodeaveclecul = malloc(sizeof(int) * ft_list_size_t(tmp))))
    return (NULL);
  while (tmp)
    {
      if (tmp->cancer == 0)
	jecodeaveclecul[i] = ft_list_size_r(tmp->room) - 1;
      else
	jecodeaveclecul[i] = -1;
      i++;
      tmp = tmp->next;
    }  
  return (jecodeaveclecul);
}

int	lance(t_room *room, t_dm *data_map)
{
  
  if (room->next)
    lance(room->next, data_map);
  if (room->fourmi != 0 && room->next != NULL)
    {
      printf("F(%d) : (%s)->(%s)\n", room->fourmi, room->name, room->next->name);
      room->next->fourmi = room->fourmi;
      room->fourmi = 0;
      return (1);
    }
  return (0);
}


int	nb_coup_total(t_dm *data_map, int *lol, int *xd)
{
  int value;
  int i;
  int j;
  
  i = 0;
  j = 0;
  value = xd[i];
  while (i < ft_list_size_t(data_map->chemin))
    {
      if (xd[i] > value)
	{
	  value = xd[i];
	  j = i;
	}
      i++;
    }
  return (value + lol[j] - 1);
}

void	launch_the_nukes(t_dm *data_map, int *xd, int *lol, int i)
{
  t_truc *chemin;
  t_room *room;
  int round;
  int ant;

  ant = 1;
  round = nb_coup_total(data_map, lol, xd);
  while (round--)
    {
      chemin = data_map->chemin;
      i = 0;
      printf("-----[%d]----\n", round + 1);
      while (chemin)
	{
	  if (xd[i] > 0)
	    {
	      room = chemin->room; 
	      if (ant <= data_map->nb_ant)
		{
		  room->fourmi = ant;
		  ant++;
		}
	      lance(room, data_map);
	    }
	  i++;
	  chemin = chemin->next;
	}
    }
}

int	*create_xd(t_dm *data_map)
{
  int *xd;
  int i;

  i = 0;
  if (!(xd = malloc(sizeof(int) * ft_list_size_t(data_map->chemin))))
    return (NULL);
  while (i < ft_list_size_t(data_map->chemin))
    {
      xd[i] = 0;
      i++;
    }
  return (xd);
}

  int	*t_nul(t_dm *data_map, int *lol)
  {
    int *xd;
    int i;
    int n;
    int ant;

    ant = data_map->nb_ant;
    n = 0;
    xd = create_xd(data_map);
    while (ant)
      {
	i = 0;
	while (i < ft_list_size_t(data_map->chemin))
	  {
	    if (lol[i] != -1)
	      {
		xd[i]++;;
		if (--ant == 0)
		  return (xd);
	      }
	    i++;
	  }
      }
    return (xd);
  }

  int		ant_ant(t_dm *data_map)
  {
    int *lol;
    int *xd;
    int i;

    i = 0;
    printf(">><<\n");
    check_list(data_map);
    if (!(lol = fill_jecodeaveclecul(data_map)))
      return (-1);
    while (i < ft_list_size_t(data_map->chemin))
      {
	printf("lol[%d][%d]\n", i, lol[i]);
	i++;
      }
    if (!(xd = t_nul(data_map, lol)))
      return (-1);
    i = 0;
    while (i < ft_list_size_t(data_map->chemin))
      {
	printf("xd[%d][%d]\n", i, xd[i]);
	i++;
      }
    launch_the_nukes(data_map, xd, lol, 0);
    //  sort(data_map, lol);
    return (1);
  }

  /*

    void   sort(t_dm *data_map, int *tab)
    {
    int	i;
    int	j;
    int	coup;
    int	ant_i;
    int	ant_j;

    i = nbcoup_lower(tab, data_map, -1);
    ant_i = data_map->nb_ant;
    while ((j = nbcoup_lower(tab, data_map, i)) != -1)
    {
    ant_j = 0;
    coup = tab[i] + ant_i - 1;
    while (tab[i] + ant_i - 1 > tab[j] + ant_j - 1)
    {
    --ant_i;
    ++ant_j;
    }
    tab[i] = -1;
    i = j;
    ft_putnbr(ant_i);
    ft_putchar('\n');
    ft_putnbr(ant_j);
    ft_putchar('\n');
    ft_putchar('\n');
    ant_i = ant_j;
    }
    ft_putnbr(ant_i);
    } 

int	nbcoup_lower(int *tab, t_dm *data_map)
{
  int	i;
  int	j;
  int	ret;

  i = 0;
  j = 0;
  ret = -1;
  while (i < ft_list_size_t(data_map->chemin))
    {
      if (tab[i] != -1)
	if (tab[j] > tab[i])
	  {
	    ret = 1;
	    j = i;
	  }
      ++i;
    }
  if (ret == -1)
    return (-1);
  return (j);
}

    _______________________
    


    void		moove_ant(t_dm *data_map, t_room *room, int *lol, int i)
    {
    int ant;

    ant = 0;
    if (lol[i] == 0)
    return ;
    lol[i]--;
    room->fourmi++;
    while (room->next)
    {
    if (room->next- > 0)
    {
    printf("ant(%d)", fourmi);
    printf("%s", room->name);
    ft_putstr("->");
    if (room->next->next == NULL) 
    {
    }
    }
    }
    }

    void		send_ant(t_dm *data_map, int *lol)
    {
    t_truc *chemin;
    t_room *room;
    int i;

  
    while (is_empty(lol))
    {
    chemin = data_map->chemin;
    i = 0;
    while (chemin)
    {
    room = chemin->room;
    moove_ant(room, lol, i);
    }
      
    }
    }
  */
