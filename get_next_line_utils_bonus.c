/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craimond <craimond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:04:12 by craimond          #+#    #+#             */
/*   Updated: 2023/11/03 13:08:38 by craimond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_single_line(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	if (str == NULL || *str == '\0')
		return (NULL);
	new_str = malloc(f_sl(str) + (str[f_sl(str) - 1] == '\n'));
	if (!new_str)
		return (NULL);
	while (str[++i] != '\0' && str[i] != '\n')
		new_str[i - 1] = str[i];
	if (i <= f_sl(str) && str[i] == '\n')
	{
		new_str[i - 1] = str[i];
		i++;
	}
	new_str[i - 1] = '\0';
	return (new_str);
}

static void	free_previous(char *ptr)
{
	while (ptr != NULL && *ptr != 127)
		(ptr)--;
	free(ptr);
}

char	*f_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		s1_len;
	int		s2_len;

	if (s1 != NULL && *s1 == 127)
		s1++;
	s1_len = f_sl(s1) + 1;
	s2_len = f_sl(s2);
	i = 0;
	newstr = malloc((s1_len + s2_len + 1));
	if (newstr != NULL)
		newstr[0] = 127;
	while (++i < s1_len)
		newstr[i] = s1[i - 1];
	i = -1;
	while (++i < s2_len)
		newstr[s1_len + i] = s2[i];
	if (newstr != NULL)
		newstr[s1_len + i] = '\0';
	free((void *)s2);
	free_previous((char *)s1);
	return (newstr);
}

int	f_sl(char *c)
{
	int	n;

	if (c == NULL)
		return (0);
	n = 0;
	while (c[n])
		n++;
	return (n);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;
	int		n;

	if (nmemb != 0 && size > ULONG_MAX / nmemb)
		return (NULL);
	n = nmemb * size;
	arr = malloc(n);
	while (arr != NULL && n-- > 0)
		arr[n] = '\0';
	return (arr);
}
