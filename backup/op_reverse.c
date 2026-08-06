/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 10:02:51 by marvin            #+#    #+#             */
/*   Updated: 2026/08/06 10:03:42 by marvin           ###   ########.fr       */
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
	print_op(ps, "rra\n");
	ps->ops.rra++;
	ps->ops.total++;
}

void	op_rrb(t_ps *ps)
{
	rev_rotate(ps->b);
	print_op(ps, "rrb\n");
	ps->ops.rrb++;
	ps->ops.total++;
}

void	op_rrr(t_ps *ps)
{
	rev_rotate(ps->a);
	rev_rotate(ps->b);
	print_op(ps, "rrr\n");
	ps->ops.rrr++;
	ps->ops.total++;
}
