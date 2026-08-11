/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 03:00:41 by marvin            #+#    #+#             */
/*   Updated: 2026/05/03 03:00:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newlst;
	void	*map;

	if (lst == NULL)
		return (NULL);
	new = NULL;
	newlst = NULL;
	map = NULL;
	while (lst != NULL)
	{
		map = f(lst->content);
		if (map == NULL)
			return (ft_lstclear(&newlst, del), NULL);
		new = ft_lstnew(map);
		if (new == NULL)
			return (del(map), ft_lstclear(&newlst, del), NULL);
		ft_lstadd_back(&newlst, new);
		lst = lst->next;
	}
	return (newlst);
}
/*
 1. iterate the list 'lst' and apply the function 'f' to the content of each node
 2. create a new list resulting of the successive applications of 
 the function 'f'
 3. the 'del' function is used to delete the content of a node if needed
 */
/* #include <stdio.h>

static void	*to_upper(void *content)
{
	return(ft_strmapi((char *)content,(char (*)(unsigned int, char))ft_toupper));
}

static void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lst;
	t_list	*result;

	lst = ft_lstnew("hello");
	ft_lstadd_back(&lst, ft_lstnew("world"));
	result = ft_lstmap(lst, to_upper, del);
	while (result)
	{
		printf("%s\n", (char *)result->content);
		result = result->next;
	}
	return (0);
}	*/