/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:25:11 by emaravil          #+#    #+#             */
/*   Updated: 2023/12/25 14:04:44 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*copy;
	size_t		slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
	{
		copy = malloc(sizeof(char));
		if (!copy)
			return (NULL);
		copy[0] = 0;
		return (copy);
	}
	if (len > (slen - start))
		len = slen - start;
	copy = malloc(len + 1);
	if (!(copy))
		return (NULL);
	ft_strlcpy(copy, &s[start], len + 1);
	return (copy);
}
