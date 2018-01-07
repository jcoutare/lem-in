/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 15:34:54 by yguzman           #+#    #+#             */
/*   Updated: 2017/12/28 16:54:22 by jcoutare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

typedef struct				s_room
{
  char						*name;
  int						fourmi;
  struct s_room				*next;
}							t_room;

typedef struct				s_truc
{
  int				cancer;
	t_room					*room;
	struct s_truc			*next;
}							t_truc;

typedef struct				s_data_map
{
	int						nb_ant;
	char					**name_room;
	char					*start;
	char					*end;
	char					**lien;
	int						nb_coup;
	t_room					*room;
	t_truc					*chemin;
}							t_dm;

typedef struct				s_tree
{
	char					*name;
	struct s_tree			*next;
	struct s_tree			**branch;
	int						what;
	int						validroom;
}							t_tree;

int						ant_ant(t_dm *data_map);
int						ft_list_size_r(t_room *begin_list);
int						ft_list_size_t(t_truc *begin_list);
void						lst_remove_last(t_room **begin_list);
t_room						*lemin_new(char *name);
t_room						*lst_copy(t_room **begin_list);
int							l_push_back(t_room **begin_list, char *name);
int							fill_list(t_tree **data, t_room *room, t_dm *data_map);
int							algo_lemdeux(t_tree **data, t_dm *data_map);
int							read_and_fill_lemin(t_tree **data, t_dm *data_map);
char						**create_cpy_file(void);
int							pars_data(char **file, t_dm *data_map);
int							check_line(char *line);
int							fill_data(t_tree **data, t_dm *data_map);
int							search_name_room(t_dm *data_map, char **file, int *i);
int							check_format_lien(char *str, t_dm *data_map);
int							check_format_room(char *str);
int							check_name(char *str, char **tab);
int							check_line_lien(char *str, t_dm *data_map, int i);
t_tree						*create_maillon(char *name, int what);
void						push_maillon(t_tree **data, t_tree *elem);
int							realloc_branch(t_tree *src, t_tree *dest);
int							search_nb_ant_start_end(char **file);
int							get_path(t_tree *data, t_dm *data_map, char *prev, int i);
int							find_start(t_tree **data, t_dm *data_map);
int							ant_ant(t_dm *data_map);

#endif
