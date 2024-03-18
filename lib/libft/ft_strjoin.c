/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:40:41 by emaravil          #+#    #+#             */
/*   Updated: 2023/12/25 16:34:47 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*out;
	char const	*p1;
	char const	*p2;
	size_t		n;

	p1 = s1;
	p2 = s2;
	if (!p1 || !p2)
		return (NULL);
	n = ft_strlen(p1) + ft_strlen(p2);
	out = malloc(sizeof(char) * (n + 1));
	if (!(out))
		return (NULL);
	if (n == 1)
	{
		out[0] = '\0';
		return (out);
	}
	ft_memset(out, 0, n);
	ft_memcpy(out, p1, ft_strlen(p1));
	ft_memcpy(out + ft_strlen(p1), p2, ft_strlen(p2));
	*(out + n) = '\0';
	return (out);
}
