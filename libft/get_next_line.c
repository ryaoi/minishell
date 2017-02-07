/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 13:44:47 by ryaoi             #+#    #+#             */
/*   Updated: 2017/01/09 19:11:43 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void					freeline(t_line **lst, t_line **origin)
{
	t_line				*ptr;
	t_line				*prev;

	ptr = *origin;
	while (ptr->fd != (*lst)->fd)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	if ((*lst)->fd == (*origin)->fd)
	{
		free((*origin)->stock);
		free(*origin);
		*origin = NULL;
		return ;
	}
	prev->next = ptr->next;
	free(ptr->stock);
	ptr->fd = 0;
	free(ptr);
}

static int				get_line(char **line, t_line **list, t_line **origin)
{
	int					i;

	i = 0;
	while ((*list)->stock[i] != '\0' && (*list)->stock[i] != '\n')
		i++;
	if ((*list)->stock[i] == '\n')
	{
		*line = ft_strsub((*list)->stock, 0, i);
		(*list)->stock = ft_strsubfree((*list)->stock, i + 1,
		ft_strlen((*list)->stock) - i + 1);
	}
	else if ((*list)->stock[i] == '\0')
	{
		if (i != 0)
			*line = ft_strsub((*list)->stock, 0, i);
		else
		{
			*line = ft_strnew(0);
			freeline(list, origin);
			return (0);
		}
		free((*list)->stock);
		(*list)->stock = ft_strnew(0);
	}
	return (1);
}

static void				new_line(t_line **list, int fd, char *stock)
{
	t_line				*ptr;
	t_line				*new;

	ptr = *list;
	new = (t_line *)malloc(sizeof(t_line));
	new->stock = ft_strdup(stock);
	new->fd = fd;
	if (!ptr)
		*list = new;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
	new->next = NULL;
}

int						my_realloc(const int fd, t_line **list)
{
	char				*stock;
	char				*prev;
	char				buffer[BUFF_SIZE + 1];
	int					ret;

	ret = 1;
	stock = ft_strnew(1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) && *buffer != 10)
	{
		if (ret == -1)
			return (ret);
		buffer[ret] = '\0';
		prev = ft_strdup(stock);
		ft_strdel(&(stock));
		stock = ft_strjoini(prev, buffer, 1);
	}
	if (*stock == 10)
		return (10);
	new_line(list, fd, stock);
	ft_strdel(&(stock));
	return (ret);
}

int						get_next_line(const int fd, char **line)
{
	static t_line		*list = NULL;
	t_line				*ptr;
	int					ret;

	ret = 1;
	ptr = list;
	if (fd < 0 || (!(line)) || BUFF_SIZE < 1)
		return (-1);
	if (!(*line))
		*line = NULL;
	while (ptr != NULL)
	{
		if (ptr->fd == fd)
			return (get_line(line, &ptr, &list));
		ptr = ptr->next;
	}
	if (ptr == NULL)
	{
		if ((ret = my_realloc(fd, &list)) == 10)
			return (0);
	}
	ptr = list;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (get_line(line, &ptr, &list));
}
