/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:27:08 by craimond          #+#    #+#             */
/*   Updated: 2023/11/03 10:41:05 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_and_null(char *to_free, char **to_null);

// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
//     int fd = open("tests/empty.txt", O_RDONLY);
// 	char *line = "start";

// 	for (int i = 0; i < 1; i++)
// 	{
// 		line = get_next_line(-4);
// 		printf("%s", line);
// 		free(line);
// 	}
//     return 0;
// }

char	*get_next_line(int fd)
{
	char		*str;
	char		*ret;
	char		*buf;
	static char	*ptr;
	int			out;

	out = 1;
	while (out != 0 && out != -1)
	{
		str = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!str)
			return (NULL);
		out = read(fd, str, BUFFER_SIZE);
		buf = f_strjoin(ptr, str);
		ptr = buf;
		ret = get_single_line(ptr);
		if (f_sl(ret) > 0
			&& (ret[f_sl(ret) - 1] == '\n' || (out < BUFFER_SIZE && out >= 0)))
		{
			ptr += f_sl(ret) + (*buf == 127);
			return (ret);
		}
		free(ret);
	}
	return (free_and_null(buf, &ptr));
}

static char	*free_and_null(char *to_free, char **to_null)
{
	free(to_free);
	*to_null = NULL;
	return (NULL);
}
