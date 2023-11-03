/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:50:28 by craimond          #+#    #+#             */
/*   Updated: 2023/11/03 12:55:10 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*free_and_null(char *to_free, char **to_null)
{
	free(to_free);
	*to_null = NULL;
	return (NULL);
}

static char	*get_nl(int fd, char **ptr)
{
	char		*str;
	char		*ret;
	char		*buf;
	int			out;

	out = 1;
	while (out != 0 && out != -1)
	{
		str = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!str)
			return (NULL);
		out = read(fd, str, BUFFER_SIZE);
		buf = f_strjoin(*ptr, str);
		*ptr = buf;
		ret = get_single_line(*ptr);
		if (f_sl(ret) > 0
			&& (ret[f_sl(ret) - 1] == '\n' || (out < BUFFER_SIZE && out >= 0)))
		{
			*ptr += f_sl(ret) + (*buf == 127);
			return (ret);
		}
		free(ret);
	}
	return (free_and_null(buf, &(*ptr)));
}

static t_fd_list *f_lstadd_back(t_fd_list **lst, t_fd_list *new)
{
	t_fd_list	*tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return (*lst);
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (tmp->next);
}

static t_fd_list	*f_lstnew(int fd)
{
	t_fd_list	*new_node;

	new_node = malloc(sizeof(t_fd_list));
	if (new_node == NULL)
		return (NULL);
	new_node->fd = fd;
	new_node->ptr = NULL;
	new_node->next = NULL;
	return (new_node);
}

static t_fd_list	*f_lstiter(t_fd_list *lst, int fd)
{
	while (lst != NULL)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_fd_list	*head;
	t_fd_list			*matching_node;

	matching_node = f_lstiter(head, fd);
	if (!matching_node)
		matching_node = f_lstadd_back(&head, f_lstnew(fd));
	return (get_nl(matching_node->fd, &(matching_node->ptr)));
}
