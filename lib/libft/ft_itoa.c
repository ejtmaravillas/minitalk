/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 22:10:11 by emaravil          #+#    #+#             */
/*   Updated: 2023/12/26 00:59:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_digits(int n);
static long int	ft_abs(int n);

char	*ft_itoa(int n)
{
	char		*out;
	size_t		digits;
	long int	num;

	num = ft_abs(n);
	digits = ft_digits(n);
	out = malloc(digits + 1);
	if (!out)
		return (NULL);
	if (n < 0)
		*out = '-';
	out += digits;
	*out-- = '\0';
	while (num)
	{
		*out-- = (num % 10) + '0';
		num /= 10;
	}
	if (n > 0)
		out++;
	else if (n == 0)
		*out = '0';
	return (out);
}

static long int	ft_abs(int n)
{
	long int	num;

	num = n;
	if (num < 0)
		num *= -1;
	return (num);
}

static size_t	ft_digits(int n)
{
	size_t		digits;
	long int	num;

	digits = 0;
	num = n;
	if (num < 0)
	{
		digits++;
		num *= -1;
	}
	if (num > 9)
	{
		while (num)
		{
			digits++;
			num /= 10;
		}
	}
	else
		digits++;
	return (digits);
}
