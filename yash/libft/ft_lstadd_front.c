/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 02:37:13 by marvin            #+#    #+#             */
/*   Updated: 2026/05/03 02:37:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*
 // add the node 'new' at the beginning of the list
 // if the list is empty, the new node becomes the first node of the list
 */
/* #include <stdio.h>

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew("second");
	ft_lstadd_front(&lst, ft_lstnew("first"));
	printf("%s\n", (char *)lst->content);
	return (0);
} */