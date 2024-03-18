/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 20:18:49 by emaravil          #+#    #+#             */
/*   Updated: 2023/12/25 17:32:52 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	slen;

	if (!*needle)
		return ((char *)haystack);
	if ((!haystack && !len) || !*haystack)
		return (NULL);
	slen = ft_strlen(needle);
	while (*haystack && len-- >= slen)
	{
		if (ft_strncmp(haystack++, needle, slen) == 0)
			return ((char *)--haystack);
	}
	return (NULL);
}
