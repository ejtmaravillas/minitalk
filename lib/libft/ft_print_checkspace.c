/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_checkspace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:16:04 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/10 22:06:09 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_continuecheckspace(t_print *tab, long n, int count);
static int	ft_continuecheckspace_b(t_print *tab, long n, int count);

int	ft_print_checkspace(t_print *tab, long n, int length)
{
	int	count;
	int	temp;

	temp = 0;
	count = 0;
	if ((!tab->zero || tab->prec >= 0 || tab->dot) && !tab->dash)
	{
		while (length-- > 0)
		{
			if (ft_checkerror(tab, ' ') < 0)
				return (-1);
			count++;
		}
	}
	tab->tlen -= count;
	temp = ft_continuecheckspace(tab, n, 0);
	if (temp < 0)
		return (-1);
	count += temp;
	return (count);
}

static int	ft_continuecheckspace(t_print *tab, long n, int count)
{
	int	temp;

	temp = 0;
	if (tab->sign || tab->sp || n < 0)
	{
		if (n < 0 && (tab->format != 'x' && tab->format != 'X'))
		{
			if (ft_checkerror(tab, '-') < 0)
				return (-1);
			count++;
		}
		else if (tab->sign && (tab->format != 'x' && tab->format != 'X'))
		{
			if (ft_checkerror(tab, '+') < 0)
				return (-1);
			count++;
		}
	}
	temp = ft_continuecheckspace_b(tab, n, 0);
	if (temp < 0)
		return (-1);
	count += temp;
	return (count);
}

static int	ft_continuecheckspace_b(t_print *tab, long n, int count)
{
	if ((!tab->sign && !(n < 0)))
	{
		if (tab->sp && (tab->format != 'x' && tab->format != 'X'))
		{
			if (ft_checkerror(tab, ' ') < 0)
				return (-1);
			count++;
		}
	}
	if (n && tab->phex)
	{
		if (ft_print_prefix(tab, tab->format) < 0)
			return (-1);
		count += 2;
	}
	return (count);
}
