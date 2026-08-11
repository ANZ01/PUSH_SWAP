/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 02:50:18 by marvin            #+#    #+#             */
/*   Updated: 2026/05/03 02:50:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
// return the last node of the list
/*#include <stdio.h>

int	main(void)
{
	t_list	*lst;

	lst = ft_lstnew("first");
	// ft_lstadd_back(&lst, ft_lstnew("second"));
	// ft_lstadd_back(&lst, ft_lstnew("last"));
	printf("%s\n", (char *)ft_lstlast(lst)->content);
	return (0);
}*/