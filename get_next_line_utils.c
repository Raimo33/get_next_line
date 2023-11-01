/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:27:37 by craimond          #+#    #+#             */
/*   Updated: 2023/11/01 11:12:42 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_line(char *str)
{
	char	*new_str;
	int		i;

	i = -1;
	if (*str == '\0')
		return (NULL);
	new_str = malloc(sizeof(char) * (f_strlen(str) + 1 + (str[f_strlen(str) - 1] == '\n')));
	if (new_str == NULL)
		return (NULL);
	while (str[++i] != '\0' && str[i] != '\n')
		new_str[i] = str[i];
	if (str[i] == '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		i;

	i = -1;
	new_str = malloc(sizeof(char) * (f_strlen(s) + 1));
	if (new_str == NULL)
		return (NULL);
	while (++i < f_strlen(s))
		new_str[i] = s[i];
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	int		i;
	int		n;
	int		s1_len;
	int		s2_len;

	s1_len = f_strlen(s1);
	s2_len = f_strlen(s2);
	i = -1;
	newstr = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (newstr == NULL)
		return (NULL);
	while (++i < s1_len)
		newstr[i] = s1[i];
	n = i;
	i = -1;
	while (++i < s2_len)
		newstr[n + i] = s2[i];
	newstr[n + i] = '\0';
	free((void *)s2);
	//free((void *)s1);
	return (newstr);
}

int	f_strlen(const char *c)
{
	int	n;

	if (c == NULL)
		return (0);
	n = 0;
	while (c[n])
		n++;
	return (n);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	int		n;

	if (nmemb != 0 && size > ULONG_MAX / nmemb)
		return (NULL);
	n = nmemb * size;
	arr = (void *)malloc(n);
	if (arr == NULL)
		return (NULL);
	while (n-- > 0)
		((char *)arr)[n] = '\0';
	return (arr);
}
