/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:10:10 by emaravil          #+#    #+#             */
/*   Updated: 2023/12/25 19:27:40 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;
	void	*content;

	if (!lst)
		return (NULL);
	new = NULL;
	while (lst)
	{
		content = f(lst->content);
		node = malloc(sizeof(t_list));
		if (!(node))
		{
			del(content);
			ft_lstclear(&new, (*del));
			return (NULL);
		}
		node->content = content;
		node->next = NULL;
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
