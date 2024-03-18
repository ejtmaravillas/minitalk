/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:58:55 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/10 22:26:48 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_count_digits(t_print *tab, long long n);
static char			*ft_get_digitstring(t_print *tab, char *p, long long n);
static int			ft_print_all(t_print *tab, const char *s, long n, int l);

int	ft_print_numbase(t_print *tab, char format)
{
	long long	n;
	int			count;
	char		*p;
	int			temp;

	count = 0;
	temp = 0;
	n = ft_get_args(tab, format);
	p = ft_count_digits(tab, n);
	if (!p)
		return (-1);
	count += ft_getprintlength(tab, p, n, tab->tlen);
	if (count < 0)
	{
		free(p);
		return (-1);
	}
	temp = ft_print_all(tab, p, n, tab->tlen);
	if (temp < 0)
	{
		free(p);
		return (-1);
	}
	free(p);
	return (count + temp);
}

static int	ft_print_all(t_print *tab, const char *s, long n, int l)
{
	int		count;

	count = 0;
	while ((l > 0) && ((tab->zero && tab->prec < 0 && !tab->dot) && !tab->dash))
	{
		if (ft_checkerror(tab, '0') < 0)
			return (-1);
		count++;
		l--;
	}
	while (*s && !(!n && tab->prec <= 0 && tab->dot))
	{
		if (ft_checkerror(tab, *s++) < 0)
			return (-1);
		count++;
	}
	while (l-- > 0 && tab->dash)
	{
		if (ft_checkerror(tab, ' ') < 0)
			return (-1);
		count++;
	}
	return (count);
}

static char	*ft_count_digits(t_print *tab, long long n)
{
	int			count;
	char		*p;
	long long	num;

	count = 0;
	num = n;
	if (n < 0)
		n *= -1;
	if (n == 0)
		count++;
	while (n)
	{
		count++;
		n = n / (tab->base);
	}
	if (tab->prec > count)
		count = tab->prec;
	p = malloc(count + 1);
	if (ft_checkerror_malloc(tab, p) < 0)
		return (NULL);
	*(p + count) = '\0';
	while (count)
		p[--count] = '0';
	p = ft_get_digitstring(tab, p, num);
	return (p);
}

static char	*ft_get_digitstring(t_print *tab, char *p, long long n)
{
	char	*sym;
	int		count;
	int		base;

	base = tab->base;
	sym = "0123456789abcdef";
	count = 0;
	if (n < 0)
		n *= -1;
	if (base == 16 && (tab->format == 'x'))
		sym = "0123456789abcdef";
	else if (base == 16 && tab->format == 'X')
		sym = "0123456789ABCDEF";
	while (p[count] != '\0')
		count++;
	while (count)
	{
		p[--count] = sym[(n % base)];
		n /= base;
	}
	return (p);
}
