/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 03:00:36 by marvin            #+#    #+#             */
/*   Updated: 2026/05/03 03:00:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*list_ptr;

	if (!lst)
		return ;
	list_ptr = lst;
	while (list_ptr != NULL)
	{
		(*f)(list_ptr->content);
		list_ptr = list_ptr->next;
	}
}

/*
 // iterate the list 'lst' and apply the function 'f' to the content of each node
 */
/* #include <stdio.h>

static void	print(void *content)
{
	printf("%s\n", (char *)content);
} 
int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew("first");
	ft_lstadd_back(&lst, ft_lstnew("second"));
	ft_lstadd_back(&lst, ft_lstnew("third"));
	ft_lstiter(lst, print);
	return (0);
}	*/