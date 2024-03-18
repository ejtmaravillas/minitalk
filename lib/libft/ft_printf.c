/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:03:41 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/10 22:43:49 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_printout(t_print *tab, const char *format);
static t_print	*ft_initialize_tab(t_print *tab);
static char		*ft_update_tab(const char *format, t_print *tab);
static char		*ft_getlength(const char *format, t_print *tab);

int	ft_printf(const char *format, ...)
{
	int		count;
	t_print	*tab;

	count = 0;
	tab = malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	va_start(tab->args, format);
	tab->count = 0;
	while (*format && ft_initialize_tab(tab))
	{
		if (*format++ == '%')
			format = ft_printout(tab, format);
		else
			tab->count += ft_checkerror(tab, *(format - 1));
		if (tab->error < 0)
		{
			free(tab);
			return (-1);
		}
	}
	count += tab->count;
	va_end(tab->args);
	free(tab);
	return (count);
}

static char	*ft_printout(t_print *tab, const char *format)
{
	char	*p;

	p = (char *)format;
	p = ft_update_tab(p, tab);
	if (*p == '%')
		tab->count += ft_printpercent(tab);
	else if (*p == 'c')
		tab->count += ft_print_c(tab);
	else if (*p == 's')
		tab->count += ft_print_s(tab);
	else if (*p == 'p')
		tab->count += ft_print_p(tab);
	else if (*p == 'd' || *p == 'i')
		tab->count += ft_print_numbase(tab, *p);
	else if (*p == 'u')
		tab->count += ft_print_numbase(tab, *p);
	else if (*p == 'x' || *p == 'X')
	{
		tab->base = 16;
		tab->count += ft_print_numbase(tab, *p);
	}
	else
		return (p);
	return (++p);
}

static t_print	*ft_initialize_tab(t_print	*tab)
{
	tab -> width = 0;
	tab -> prec = -1;
	tab -> zero = 0;
	tab -> pnt = 0;
	tab -> sign = 0;
	tab -> tlen = 0;
	tab -> dash = 0;
	tab -> sp = 0;
	tab -> phex = 0;
	tab -> base = 10;
	tab -> format = 'c';
	tab -> dot = 0;
	tab -> error = 0;
	return (tab);
}

static char	*ft_update_tab(const char *format, t_print *tab)
{
	while (*format)
	{
		if (*format == '#')
			tab->phex = 1;
		else if (*format == '-')
			tab->dash = 1;
		else if (*format == '+')
			tab->sign = '+';
		else if (*format == ' ')
			tab->sp = 1;
		else if (*format == '0')
			tab->zero = 1;
		else
			break ;
		format++;
	}
	format = ft_getlength(format, tab);
	return ((char *)format);
}

static char	*ft_getlength(const char *format, t_print *tab)
{
	int	len;
	int	prec;

	len = 0;
	prec = tab->prec;
	while ((*format <= '9') && (*format >= '0'))
		len = (10 * len) + (*format++ - '0');
	tab->tlen = len;
	if (*format == '.')
	{
		tab->dot = 1;
		if ((*++format <= '9') && (*format >= '0'))
			prec = 0;
		while ((*format <= '9') && (*format >= '0'))
			prec = (10 * prec) + (*format++ - '0');
		tab->prec = prec;
	}
	tab->format = *format;
	return ((char *)format);
}
