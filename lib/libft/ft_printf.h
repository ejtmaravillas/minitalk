/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:00:36 by emaravil          #+#    #+#             */
/*   Updated: 2024/01/10 22:26:03 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_print
{
	va_list	args;
	int		width;
	int		prec;
	int		zero;
	int		pnt;
	int		dash;
	int		tlen;
	char	sign;
	int		sp;
	int		phex;
	int		base;
	char	format;
	int		count;
	int		dot;
	int		error;
}	t_print;

int			ft_printpercent(t_print *tab);
int			ft_print_prefix(t_print *tab, char c);
int			ft_print_s(t_print *tab);
int			ft_print_p(t_print *tab);
int			ft_print_c(t_print *tab);
int			ft_printf(const char *format, ...);
int			ft_print_numbase(t_print *tab, char format);
size_t		ft_strlen(const char *arg);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_checkerror(t_print *tab, char c);
int			ft_checkerror_malloc(t_print *tab, char *error_malloc);
int			ft_print_checkspace(t_print *tab, long n, int length);
int			ft_getprintlength(t_print *tab, const char *p, long long n, int l);
long long	ft_get_args(t_print *tab, char format);

#endif