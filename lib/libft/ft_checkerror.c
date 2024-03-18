/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 22:53:00 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/10 17:27:27 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkerror(t_print *tab, char c)
{
	int	temp;

	temp = 0;
	temp = write(1, &c, 1);
	if (temp == -1)
	{
		tab->error = -1;
		return (-1);
	}
	return (1);
}
