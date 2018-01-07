/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YoannG <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 17:00:25 by YoannG            #+#    #+#             */
/*   Updated: 2016/11/16 22:22:44 by yguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

t_list				*check_and_push_fd(int fd, t_list **list_fd)
{
	t_list			*ret;

	if (fd < 0)
		return (NULL);
	ret = *list_fd;
	while (ret)
	{
		if (fd == (int)ret->content_size)
			return (ret);
		ret = ret->next;
	}
	if ((list_push_back(list_fd, NULL, fd)) == -1)
		return (NULL);
	ret = *list_fd;
	while (ret->next)
		ret = ret->next;
	return (ret);
}

int					realloc_and_cpy_line(char **buff, char **str, int len)
{
	char			*tmp;
	char			*tmp2;

	if ((*str = ft_reallocfake(*str, ft_strlen(*str) + 1, len + 1)) == NULL)
		return (-1);
	if (ft_strcat(*str, (tmp2 = ft_strsub(*buff, 0, len))) == NULL)
		return (-1);
	free(tmp2);
	if ((*buff)[len] == '\n')
	{
		if ((tmp = malloc(sizeof(char *) * (ft_strlen(*buff) - (len)))) == NULL)
			return (-1);
		ft_memcpy(tmp, (*buff) + (len + 1), ft_strlen(*buff) - (len));
		free(*buff);
		*buff = tmp;
		return (0);
	}
	free(*buff);
	*buff = NULL;
	return (0);
}

static int			read_line(char **buff, char **str, t_list *elem)
{
	int				len;

	len = 0;
	*buff = (char *)elem->content;
	while ((*buff)[len])
	{
		if ((*buff)[len] == '\n')
		{
			if (realloc_and_cpy_line(buff, str, len) == -1)
				return (-1);
			elem->content = *buff;
			return (1);
		}
		++len;
	}
	if (realloc_and_cpy_line(buff, str, len) == -1)
		return (-1);
	elem->content = *buff;
	if (*str[0] == 0)
	{
		free(*str);
		*str = NULL;
	}
	return (0);
}

int					read_buff_size(int fd, t_list *elem, char **line)
{
	int				ret;
	char			*tmp;
	char			buff[BUFF_SIZE + 1];

	if (elem->content != NULL)
	{
		if ((ret = read_line(&tmp, line, elem)) == -1)
			return (-1);
		if (ret == 1)
			return (1);
	}
	ft_memset(buff, 0, BUFF_SIZE + 1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (((elem->content = ft_strdup(buff)) == NULL) ||
			((ret = read_line(&tmp, line, elem)) == -1))
			return (-1);
		if (ret == 1)
			return (1);
	}
	if (ret > 0 && *line)
		if ((ret = read_buff_size(fd, elem, line)) == -1)
			return (-1);
	return (ret == -1 ? -1 : 0);
}

int					get_next_line(int fd, char **line)
{
	int				ret;
	static t_list	*list_fd;
	t_list			*elem;

	if (line == NULL)
		return (-1);
	*line = NULL;
	if ((elem = check_and_push_fd(fd, &list_fd)) == NULL)
		return (-1);
	if ((ret = read_buff_size(fd, elem, line)) == -1)
		return (-1);
	if (ret == 1)
		return (1);
	free_elem(&list_fd, elem);
	if (*line != NULL && (*line)[0] == '\0')
	{
		if ((*line)[0] == '\0')
			free(*line);
		return (0);
	}
	else if (*line != NULL)
		return (1);
	return (0);
}
