/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:27:08 by craimond          #+#    #+#             */
/*   Updated: 2023/11/02 16:36:38 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line_utils.c"
// #define BUFFER_SIZE 100

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*str;
	char		*ret;
	char		*buf;
	static char	*ptr;
	int			out;

	while (1)//fermarsi all'ultima riga)
	{
		str = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!str)
			return (NULL);
		out = read(fd, str, BUFFER_SIZE);
		if (out < 0) //riducibile col trucchetto
		{
			free(str);
			//free(buf);
			ptr = NULL;
			return (NULL);
		}
		buf = f_strjoin(ptr, str);
		ptr = buf;
		ret = get_single_line(ptr);
		if (f_slen(ret) > 0 && (ret[f_slen(ret) - 1] == '\n' || out < BUFFER_SIZE)) //riducibile col trucchetto
		{
			ptr += f_slen(ret) + (*buf == 127);
			return (ret);
		}
		free(ret);
		if (out == 0)
		{
			free(buf);
			ptr = NULL;
			return (NULL);
		}
	}
}

// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
//     int fd = open("tests/empty.txt", O_RDONLY);
// 	char *line = "start";

// 	for (int i = 0; i < 1; i++)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 	}
//     return 0;
// }
