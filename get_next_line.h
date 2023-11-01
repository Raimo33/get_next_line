/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:27:55 by craimond          #+#    #+#             */
/*   Updated: 2023/10/31 22:27:56 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_UTILS_H
# define GET_NEXT_LINE_UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char    *get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
void	*ft_memset(void *str, int c, size_t n);
int		f_strlen(const char *c);
char    *get_line(char *str);

#endif
