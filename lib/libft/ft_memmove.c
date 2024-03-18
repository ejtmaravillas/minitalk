/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:19:34 by emaravil          #+#    #+#             */
/*   Updated: 2023/12/26 01:28:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (!d && !s)
		return (NULL);
	if (d > s)
	{
		s += len - 1;
		d += len - 1;
		while (len--)
			*d-- = *s--;
	}
	else if (d < s)
		while (len--)
			*d++ = *s++;
	return (dst);
}
