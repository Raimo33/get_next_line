/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:50:37 by craimond          #+#    #+#             */
/*   Updated: 2023/11/03 12:07:34 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				fd;
	char			*ptr;
	struct s_list	*next;
}						t_fd_list;

char	*get_next_line(int fd);
char	*f_strjoin(char *s1, char *s2);
char	*ft_calloc(size_t nmemb, size_t size);
int		f_sl(char *c);
char	*get_single_line(char *str);
char	*ft_strdup(char *s);

#endif