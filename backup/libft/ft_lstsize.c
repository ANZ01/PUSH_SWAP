/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 02:39:26 by marvin            #+#    #+#             */
/*   Updated: 2026/05/03 02:39:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*node;

	node = lst;
	count = 0;
	while (node != NULL)
	{
		count++;
		node = node->next;
	}
	return (count);
}
/*
 // count the number of nodes in a linked list
 // return the count
 */
/* #include <stdio.h>

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew("first");
	ft_lstadd_back(&lst, ft_lstnew("second"));
	ft_lstadd_back(&lst, ft_lstnew("third"));
	printf("%d\n", ft_lstsize(lst));
	return (0);
}	*/