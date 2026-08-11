/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 02:57:32 by marvin            #+#    #+#             */
/*   Updated: 2026/05/03 02:57:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (!lst)
		return ;
	while (*lst)
	{
		node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = node;
	}
}
/*
 1. delete and free the given node and every successor of 
 that node, using the function 'del' and free(3)
 2. finally, the pointer to the list must be set to NULL
 */
/* #include <stdio.h>

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew("first");
	ft_lstadd_back(&lst, ft_lstnew("second"));
	ft_lstadd_back(&lst, ft_lstnew("third"));
	ft_lstclear(&lst, NULL);
	printf("%s\n", lst == NULL ? "list is NULL" : "list is NOT NULL");
	return (0);
} */