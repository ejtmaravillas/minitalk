/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:23:07 by emaravil          #+#    #+#             */
/*   Updated: 2023/12/25 11:18:01 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	unsigned char	*p;
	unsigned char	cmp;

	cmp = (unsigned char)c;
	p = (unsigned char *)src;
	while (len--)
		if (*p++ == cmp)
			return ((char *)(--p));
	return (NULL);
}
