/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:27:08 by craimond          #+#    #+#             */
/*   Updated: 2023/10/31 23:33:29 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_everything(char *ptr);

char    *get_next_line(int fd)
{
	char 		*str;
	char		*to_return;
	static char	*buf;
	int			i;

	i = 0;
	if (!buf)
		buf = malloc(BUFFER_SIZE * 2 + 1);
	str = malloc(BUFFER_SIZE + 1);
	if (str == NULL)
		return (NULL);
	read(fd, str, BUFFER_SIZE);
	str[BUFFER_SIZE] = '\0';
	buf = ft_strjoin(buf, str);
	to_return = get_line(buf);
	if (to_return[f_strlen(to_return) - 1] == '\n') //va in segfault sull'ultima linea perche' termina con \0 e non trova il \n
	{
		while (*buf != '\n' && *buf != '\0')
			buf++;
		buf++;
		return(to_return); //se to_return e' effettivamente una linea allora ritornala
	}
	return (NULL); //altrimenti ritorna NULL perche' con la BUFFER_SIZE di queste dimensioni non e' stata trovata nessuna linea
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
		printf("%s", get_next_line(fd));
    return 0;
}
