/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:58:55 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/10 17:42:40 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_address(t_print *tab, unsigned long n, int base, char c);
static int	ft_count_digits(t_print *tab, unsigned long long n);
static int	ft_checknull(t_print *tab, void *n);
static int	ft_checkwrite_error(t_print *tab, int digits, int count);

int	ft_print_p(t_print *tab)
{
	void	*n;
	int		count;
	int		digits;
	int		temp;

	n = va_arg(tab->args, void *);
	count = 0;
	temp = 0;
	tab->base = 16;
	digits = ft_count_digits(tab, (unsigned long)n);
	if (!n && tab->dot)
		digits = 0;
	temp = ft_checkwrite_error(tab, digits, count);
	if (temp < 0)
		return (-1);
	count += temp;
	temp = ft_checknull(tab, n);
	if (temp < 0)
		return (-1);
	count += temp;
	return (count);
}

static int	ft_checkwrite_error(t_print *tab, int digits, int count)
{
	if (tab->tlen > digits && !tab->dash)
	{
		while (count < tab->tlen - (digits + 2))
		{
			if (ft_checkerror(tab, ' ') < 0)
				return (-1);
			count++;
		}
	}
	if (tab->sign || tab->sp)
	{
		if (tab->sign)
		{
			if (ft_checkerror(tab, '+') < 0)
				return (-1);
			count++;
		}
		else if (tab->sp)
		{
			if (ft_checkerror(tab, ' ') < 0)
				return (-1);
			count++;
		}
	}
	return (count);
}

static int	ft_checknull(t_print *tab, void *n)
{
	int	count;
	int	temp;

	temp = 0;
	count = 0;
	temp = ft_print_prefix(tab, 'p');
	if (temp < 0)
		return (-1);
	count += temp;
	if (!n && tab->dot)
		return (count);
	count += ft_print_address(tab, (unsigned long)n, 16, 'p');
	while (count < tab->tlen && tab->tlen > 0 && tab->dash)
	{
		if (ft_checkerror(tab, ' ') < 0)
			return (-1);
		count++;
	}
	return (count);
}

static int	ft_print_address(t_print *tab, unsigned long n, int base, char c)
{
	int		count;
	char	*sym;

	count = 0;
	sym = "0123456789abcdef";
	if (n < (unsigned long)base)
	{
		if (ft_checkerror(tab, sym[n]) < 0)
			return (-1);
		return (1);
	}
	else
	{
		count = ft_print_address(tab, (n / base), base, c);
		if (count == -1)
			return (count);
		return (count += ft_print_address(tab, n % base, base, c));
	}
	return (count);
}

static int	ft_count_digits(t_print *tab, unsigned long long n)
{
	int			count;

	count = 0;
	if (n == 0)
		count++;
	while (n)
	{
		count++;
		n = n / (tab->base);
	}
	return (count);
}
