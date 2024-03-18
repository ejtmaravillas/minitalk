/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:44:48 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/10 17:23:13 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_prefix(t_print *tab, char c)
{
	int	count;

	count = 0;
	if (c == 'X')
	{
		if (ft_checkerror(tab, '0') < 0)
			return (-1);
		count++;
		if (ft_checkerror(tab, 'X') < 0)
			return (-1);
		count++;
	}
	else if (c == 'x' || c == 'p')
	{
		if (ft_checkerror(tab, '0') < 0)
			return (-1);
		count++;
		if (ft_checkerror(tab, 'x') < 0)
			return (-1);
		count++;
	}
	return (count);
}
