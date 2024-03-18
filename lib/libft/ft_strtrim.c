/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:17:50 by emaravil          #+#    #+#             */
/*   Updated: 2023/12/25 18:50:55 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_checkchar(char *s1, char *set, int rev);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*end;
	char	*s;
	char	*out;
	int		rev;

	if (!s1 || !set)
		return (NULL);
	rev = 0;
	s = ft_checkchar((char *)s1, (char *)set, rev);
	if (!*s)
	{
		out = malloc(sizeof(char));
		if (!out)
			return (NULL);
		out[0] = 0;
		return (out);
	}
	end = s + ft_strlen(s) - 1;
	rev = 1;
	end = ft_checkchar(end, (char *)set, rev);
	out = malloc((end - s) + 2);
	if (!out)
		return (NULL);
	ft_strlcpy(out, s, (end - s) + 2);
	return (out);
}

static char	*ft_checkchar(char *s1, char *set, int rev)
{
	char	*s;

	s = set;
	while (*s && *s1)
	{
		if ((*s == *s1) && !rev)
		{
			s1++;
			s = set;
			continue ;
		}
		else if ((*s == *s1) && rev)
		{
			s1--;
			s = set;
			continue ;
		}
		s++;
	}
	return (s1);
}
