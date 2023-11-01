/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:27:08 by craimond          #+#    #+#             */
/*   Updated: 2023/11/01 11:14:58 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_utils.c"
#define BUFFER_SIZE 100

//#include "get_next_line.h"

static char	*free_everything(char *ptr);

char    *get_next_line(int fd)
{
	char 		*str;
	char		*ret;
	static char	*buf;
	int			out;

	if (fd < 0)
		return (NULL);
	str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		return (NULL);
	out = read(fd, str, BUFFER_SIZE);
	if (out < 0)
		return (NULL);
	buf = ft_strjoin(ft_strdup(buf), str);
	ret = get_line(buf);
	if (f_strlen(ret) > 0 && ret[f_strlen(ret) - 1] == '\n' || out < BUFFER_SIZE)
	{
		buf += f_strlen(ret);
		return(ret);
	}
	return (NULL);
}

static char	*free_everything(char *ptr)
{
	while (*ptr != 127)
		ptr--;
	free(ptr);
	return (NULL);
}

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
	char *line = "start";

	for (int i = 0; i < 100; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free (line);
	}
    return 0;
}
