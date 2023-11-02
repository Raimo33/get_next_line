/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:27:08 by craimond          #+#    #+#             */
/*   Updated: 2023/11/02 12:33:51 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line_utils.c"
// #define BUFFER_SIZE 100

#include "get_next_line.h"

static void	free_previous(char *ptr);

char	*get_next_line(int fd)
{
	char		*str;
	char		*ret;
	char		*buf;
	static char	*ptr;
	int			out;

	if (fd < 0)
		return (NULL);
	str = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!str)
		return (NULL);
	out = read(fd, str, BUFFER_SIZE);
	if (out < 0)
		return (NULL);
	buf = f_strjoin(ptr, str);
	free_previous(ptr);
	ptr = buf;
	ret = get_single_line(ptr);
	if (f_slen(ret) > 0 && (ret[f_slen(ret) - 1] == '\n' || out < BUFFER_SIZE)) //riducibile di 1 riga col trucchetto
	{
		ptr += f_slen(ret) + (*buf == 127);
		return (ret);
	}
	free(ret);
	return (NULL);
}

static void	free_previous(char *ptr)
{
	if (ptr == NULL)
		return ;
	while (*ptr != 127)
		(ptr)--;
	free(ptr);
}

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
	char *line = "start";

	for (int i = 0; i < 27; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
    return 0;
}
