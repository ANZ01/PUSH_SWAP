/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/06/16 00:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_new(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*stack_new(void)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
	return (s);
}

void	stack_free(t_stack *s)
{
	t_node	*cur;
	t_node	*next;

	if (!s)
		return ;
	cur = s->top;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(s);
}

t_ps	*ps_new(void)
{
	t_ps	*ps;

	ps = (t_ps *)malloc(sizeof(t_ps));
	if (!ps)
		return (NULL);
	ps->a = stack_new();
	ps->b = stack_new();
	if (!ps->a || !ps->b)
	{
		ps_free(ps);
		return (NULL);
	}
	ps->strategy = ADAPTIVE;
	ps->bench_mode = FALSE;
	ps->disorder = 0.0;
	ft_bzero(&ps->ops, sizeof(t_bench));
	return (ps);
}

void	ps_free(t_ps *ps)
{
	if (!ps)
		return ;
	stack_free(ps->a);
	stack_free(ps->b);
	free(ps);
}
