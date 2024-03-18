/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utilsb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 01:03:50 by emaravil          #+#    #+#             */
/*   Updated: 2024/02/07 01:12:32 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

bool	check_string_arg(char *newline)
{
	if (!(ft_strncmp(newline, "sa\n", 3)))
		return (true);
	else if (!(ft_strncmp(newline, "sb\n", 3)))
		return (true);
	else if (!(ft_strncmp(newline, "ra\n", 3)))
		return (true);
	else if (!(ft_strncmp(newline, "rb\n", 3)))
		return (true);
	else if (!(ft_strncmp(newline, "rra\n", 4)))
		return (true);
	else if (!(ft_strncmp(newline, "rrb\n", 4)))
		return (true);
	else if (!(ft_strncmp(newline, "pa\n", 3)))
		return (true);
	else if (!(ft_strncmp(newline, "pb\n", 3)))
		return (true);
	else if (!(ft_strncmp(newline, "rr\n", 3)))
		return (true);
	else if (!(ft_strncmp(newline, "rrr\n", 4)))
		return (true);
	else
		return (false);
}
