/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:11:06 by emaravil          #+#    #+#             */
/*   Updated: 2023/12/25 12:52:04 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	cmp = c;
	size_t		n;

	n = ft_strlen(s) + 1;
	while (n--)
	{
		if (*s == cmp)
			return ((char *)(s));
		if (!*s)
			return (NULL);
		s++;
	}
	return (NULL);
}

//const char cpm = char --> declare init value of cmp