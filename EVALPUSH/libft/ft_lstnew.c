/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 02:29:01 by marvin            #+#    #+#             */
/*   Updated: 2026/05/03 02:29:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
1. The function `ft_lstnew` takes a single argument,
`content`, which is a pointer to any type of data.
It returns a pointer to a new node of type `t_list`.
2. Inside the function, we first allocate memory for a new node
using `malloc`. We check if the allocation was successful; if not,
we return `NULL`.
3. If the allocation is successful, we set the `content` field of the new node
to the value passed as an argument and initialize the `next` pointer to `NULL`.
4. Finally, we return the pointer to the newly created node.
*/
/*#include <stdio.h>

int	main(void)
{
	t_list	*node;

	node = ft_lstnew("hello");
	printf("%s\n", (char *)node->content);
	return (0);
} */