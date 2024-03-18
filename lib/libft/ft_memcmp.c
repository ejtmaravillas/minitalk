/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:23:24 by emaravil          #+#    #+#             */
/*   Updated: 2023/12/25 11:32:16 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	const unsigned char	*p1 = s1;
	const unsigned char	*p2 = s2;

	if (len != 0)
		while (len--)
			if (*p1++ != *p2++)
				return (*--p1 - *--p2);
	return (0);
}
