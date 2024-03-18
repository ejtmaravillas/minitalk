/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:08:42 by emaravil          #+#    #+#             */
/*   Updated: 2023/12/25 19:20:38 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*lst_ptr;

	if (!lst)
		return ;
	lst_ptr = lst;
	while (lst_ptr != NULL)
	{
		(*f)(lst_ptr->content);
		lst_ptr = lst_ptr->next;
	}
}
