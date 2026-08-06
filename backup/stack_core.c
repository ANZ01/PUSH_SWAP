/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 10:04:51 by marvin            #+#    #+#             */
/*   Updated: 2026/08/06 10:04:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_push_top(t_stack *s, t_node *node)
{
	if (!s || !node)
		return ;
	node->next = s->top;
	node->prev = NULL;
	if (s->top)
		s->top->prev = node;
	else
		s->bottom = node;
	s->top = node;
	s->size++;
}

void	stack_push_bottom(t_stack *s, t_node *node)
{
	if (!s || !node)
		return ;
	node->prev = s->bottom;
	node->next = NULL;
	if (s->bottom)
		s->bottom->next = node;
	else
		s->top = node;
	s->bottom = node;
	s->size++;
}

t_node	*stack_pop_top(t_stack *s)
{
	t_node	*node;

	if (!s || !s->top)
		return (NULL);
	node = s->top;
	s->top = node->next;
	if (s->top)
		s->top->prev = NULL;
	else
		s->bottom = NULL;
	node->next = NULL;
	node->prev = NULL;
	s->size--;
	return (node);
}

t_bool	stack_is_sorted(t_stack *s)
{
	t_node	*cur;

	if (!s || s->size <= 1)
		return (TRUE);
	cur = s->top;
	while (cur->next)
	{
		if (cur->index > cur->next->index)
			return (FALSE);
		cur = cur->next;
	}
	return (TRUE);
}

t_node	*stack_min(t_stack *s)
{
	t_node	*cur;
	t_node	*min;

	if (!s || !s->top)
		return (NULL);
	min = s->top;
	cur = min->next;
	while (cur)
	{
		if (cur->index < min->index)
			min = cur;
		cur = cur->next;
	}
	return (min);
}
