/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 02:55:21 by marvin            #+#    #+#             */
/*   Updated: 2026/05/03 02:55:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	free(lst);
}

/*
 1. take as a parameter a node and free the memory of the node’s
  content using the function 'del' given as a parameter and free the node
 2. the memory of 'next' must not be freed
 */
/*#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	*node;

	node = ft_lstnew(malloc(10));
	ft_lstdelone(node, free);
	printf("node deleted\n");
	return (0);
}*/