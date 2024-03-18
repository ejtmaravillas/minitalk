/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprintlength.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:46:49 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/10 22:39:12 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_getprintlength(t_print *tab, const char *p, long long n, int l)
{
	char	*q;
	int		count;

	count = 0;
	q = (char *)p;
	while (*q && (!(!n && tab->prec <= 0 && tab->dot)))
		q++;
	l -= (q - p);
	if ((tab->sign || tab->sp || n < 0)
		&& (tab->format != 'x' && tab->format != 'X'))
		l--;
	if (((n && tab->phex) && (tab->format == 'x' || tab->format == 'X')))
		l -= 2;
	tab->tlen = l;
	count = ft_print_checkspace(tab, n, l);
	return (count);
}
