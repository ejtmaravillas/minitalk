/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:58:33 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/10 17:36:48 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(t_print *tab)
{
	char	c;
	int		count;

	count = 0;
	c = va_arg(tab->args, int);
	if (tab->tlen > 0 && !tab->dash)
	{
		while (count < tab->tlen - 1)
		{
			if (ft_checkerror(tab, ' ') < 0)
				return (-1);
			count++;
		}
	}
	if (ft_checkerror(tab, c) < 0)
		return (-1);
	count++;
	while (count < tab->tlen && tab->tlen > 0 && tab->dash)
	{
		if (ft_checkerror(tab, ' ') < 0)
			return (-1);
		count++;
	}
	return (count);
}
