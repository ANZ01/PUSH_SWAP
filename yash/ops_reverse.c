/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/06/16 00:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack *s)
{
	t_node	*node;

	if (!s || s->size < 2)
		return ;
	node = s->bottom;
	s->bottom = node->prev;
	if (s->bottom)
		s->bottom->next = NULL;
	node->prev = NULL;
	node->next = s->top;
	if (s->top)
		s->top->prev = node;
	s->top = node;
}

void	op_rra(t_ps *ps)
{
	rev_rotate(ps->a);
	ft_putstr_fd("rra\n", 1);
	ps->ops.rra++;
	ps->ops.total++;
}

void	op_rrb(t_ps *ps)
{
	rev_rotate(ps->b);
	ft_putstr_fd("rrb\n", 1);
	ps->ops.rrb++;
	ps->ops.total++;
}

void	op_rrr(t_ps *ps)
{
	rev_rotate(ps->a);
	rev_rotate(ps->b);
	ft_putstr_fd("rrr\n", 1);
	ps->ops.rrr++;
	ps->ops.total++;
}
