/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerror_malloc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:54:30 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/10 17:32:09 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkerror_malloc(t_print *tab, char *error_malloc)
{
	if (!error_malloc)
	{
		tab->error = -1;
		return (-1);
	}
	return (1);
}
