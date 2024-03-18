/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 21:01:32 by emaravil          #+#    #+#             */
/*   Updated: 2023/12/25 14:33:03 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c);
static char		**ft_free(char **ret, int j);
static char		*ft_checkdelimiter(char const *s, char c, int opt);	

char	**ft_split(char const *s, char c)
{
	char	**out;
	char	**res;

	if (!s)
		return (NULL);
	out = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!out)
		return (NULL);
	res = out;
	while (*s)
	{
		s = ft_checkdelimiter(s, c, 1);
		if (*s)
		{
			if (!(ft_strchr(s, c)))
				*out = ft_substr(s, 0, ft_strlen(s));
			else
				*out = ft_substr(s, 0, ft_strchr(s, c) - s);
			if (!*out++)
				return (ft_free(res, (--out - res + 1)));
		}
		s = ft_checkdelimiter(s, c, 0);
	}
	*out = NULL;
	return (res);
}

static size_t	ft_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while ((*s != c) && *s)
			s++;
	}
	return (count);
}

static char	**ft_free(char **out, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(out[i]);
		i++;
	}
	free(out);
	return (NULL);
}

static char	*ft_checkdelimiter(char const *s, char c, int opt)
{
	char	*p;

	p = (char *)s;
	while ((*p != c) && *p && !opt)
		p++;
	while ((*p == c) && *p && opt)
		p++;
	return (p);
}
