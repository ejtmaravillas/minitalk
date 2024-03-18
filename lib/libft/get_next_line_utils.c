/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:11:57 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/19 14:46:37 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_gnl(char *str)
{
	size_t	i;
	size_t	len;
	char	*s;

	len = ft_strlen_gnl(str) + 1;
	s = malloc(len);
	if (!s)
		return (NULL);
	i = -1;
	while (++i < len)
		s[i] = str[i];
	return (s);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

char	*ft_strchr_gnl(const char *str, int n)
{
	char	*tmp;

	tmp = (char *)str;
	while (*tmp != (char)n)
	{
		if (*tmp == 0)
			return (NULL);
		tmp++;
	}
	return (tmp);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1;
	str = malloc(size);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}

void	*ft_calloc_gnl(size_t buffer)
{
	char	*p;
	size_t	count;

	if (buffer == 0)
		return (NULL);
	p = malloc(buffer);
	if (!p)
		return (NULL);
	count = 0;
	while (count < buffer)
	{
		p[count] = 0;
		count++;
	}
	return (p);
}
