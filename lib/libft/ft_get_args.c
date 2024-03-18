/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:35:56 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/10 21:36:32 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_get_args(t_print *tab, char format)
{
	long long	n;

	if (format == 'd' || format == 'i')
		n = va_arg(tab->args, int);
	else if (format == 'u')
		n = va_arg(tab->args, unsigned int);
	else if (format == 'x' || format == 'X')
		n = va_arg(tab->args, unsigned int);
	else
		return (0);
	return (n);
}
