/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:22:17 by emaravil          #+#    #+#             */
/*   Updated: 2023/12/25 18:34:40 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *p, int ch)
{
	char	c;
	size_t	len;

	c = (char)ch;
	len = ft_strlen(p) + 1;
	while (len--)
		if (p[len] == c)
			return ((char *)&p[len]);
	return (NULL);
}
