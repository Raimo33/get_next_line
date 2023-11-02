/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:27:55 by craimond          #+#    #+#             */
/*   Updated: 2023/11/02 16:48:47 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*f_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
int		f_sl(char *c);
char	*get_single_line(char *str);
char	*ft_strdup(char *s);

#endif
