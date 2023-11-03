/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:50:28 by craimond          #+#    #+#             */
/*   Updated: 2023/11/03 15:58:06 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line_utils_bonus.c"

#include "get_next_line_bonus.h"

// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
//     int fd = open("1char", O_RDONLY);
// 	int fd2 = open("2char", O_RDONLY);
// 	int fd3 = open("3char", O_RDONLY);
// 	int fd4 = open("4char", O_RDONLY);
// 	int fd5 = -7;

// 	char *line = "start";
// 	char *line2 = "start";
// 	char *line3 = "start";
// 	char *line4 = "start";
// 	char *line5 = "start";

// 	for (int i = 0; i < 6; i++)
// 	{
// 		line = get_next_line(fd);
// 		line2 = get_next_line(fd2);
// 		line3 = get_next_line(fd3);
// 		line4 = get_next_line(fd4);
// 		line5 = get_next_line(fd5);
// 		printf("%s\n", line);
// 		printf("%s\n", line2);
// 		printf("%s\n", line3);
// 		printf("%s\n", line4);
// 		printf("%s\n", line5);
// 		free(line);
// 		free(line2);
// 		free(line3);
// 		free(line4);
// 		free(line5);
// 	}
// 	close(fd);
// 	close(fd2);
// 	close(fd3);
// 	close(fd4);
// 	close(fd5);
//     return 0;
// }

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

static t_fd_list	*f_lstadd_back(t_fd_list **lst, t_fd_list *new)
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

// void	del_node(t_fd_list *head)
// {
// 	t_fd_list	*tmp;

// 	while (head->next && head->next->ptr != NULL)
// 		head = head->next;
// 	tmp = head->next;
// 	head->next = tmp->next;
// 	free(tmp);
// }

char	*get_next_line(int fd)
{
	static t_fd_list	*head;
	t_fd_list			*tmp;
	t_fd_list			*matching_node;
	char				*to_return;

	if (fd < 0 || fd > __FD_SETSIZE)
		return (NULL);
	tmp = head;
	matching_node = NULL;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			matching_node = tmp;
		if (tmp->fd == fd)			
			break ;
		tmp = tmp->next;
	}
	if (!matching_node)
		matching_node = f_lstadd_back(&head, f_lstnew(fd));
	if (!head || !matching_node)
		return (NULL);
	to_return = get_nl(matching_node->fd, &(matching_node->ptr));
	// del_node(head);
	return (to_return);
}
