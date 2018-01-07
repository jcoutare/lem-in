/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguzman <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 20:16:14 by yguzman           #+#    #+#             */
/*   Updated: 2017/10/10 13:54:45 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 1024
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	long			nb;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

int					get_next_line(int fd, char **line);
void				*ft_reallocfake(void *ptr, size_t size_ptr, size_t size);
int					list_push_back(t_list **list, void *content, size_t size);
void				free_elem(t_list **list, t_list *elem);
void				ft_swap(int *a, int *b);
int					ft_puterr(char *str);
void				*ft_puterr_null(char *str);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstadd_double(t_list **alst, t_list *new);
void				ft_lstdel_double(t_list **alst, t_list *del);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *str);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_putendl(char const *str);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_bzero(void *s, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
int					ft_tolower(int c);
size_t				ft_strlen(const char *str);
int					ft_tablen(char **str);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **ap);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strncat(char *dest, const char *src, size_t nb);
int					ft_strlcpy(char *dest, char *src, int size);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *meule_de_foin, const char *aiguille);
char				*ft_strnstr(const char *meule_de_foin, const char *aiguille,
								size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcat(char *dest, const char *src);
char				**ft_strsplit(char const *str, char *c);
void				ft_putnbr_base(int nbr, char *base);
void				ft_putnbr(int n);
char				*ft_itoa(int n);
void				ft_print_words_tables(char **tab);
int					ft_atoi(const char *nptr);
void				ft_putstr_color(char *str, int color);
char				*ft_getenv(char *name, t_list *my_env);
int					ft_isspace(int c);
int					find_char_in_str(char c, char *str);
int					ft_atoi_oct(char *str);
char				*ft_itoa_base(long long int value, char *base);
char				*ft_itoa_base_u(unsigned long long int value,
									char *base);
void				ft_putstr_null(char *str);

char				**realloc_tab(char **tab, char *str);

#endif
