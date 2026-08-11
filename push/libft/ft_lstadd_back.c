/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 02:47:27 by marvin            #+#    #+#             */
/*   Updated: 2026/05/03 02:47:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*
// add the node 'new' at the end of the list
// if the list is empty, the new node becomes the first node of the list
*/
/* #include <stdio.h>

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew("first");
	ft_lstadd_back(&lst, ft_lstnew("second"));
	printf("%s\n", (char *)lst->next->content);
	return (0);
}  */