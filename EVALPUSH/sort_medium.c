/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 02:21:33 by dmaurici          #+#    #+#             */
/*   Updated: 2026/08/11 02:24:23 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

static void	push_one_chunk(t_ps *ps, int lo, int hi)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = ps->a->size;
	while (i-- > 0 && pushed < hi - lo)
	{
		if (ps->a->top->index >= lo && ps->a->top->index < hi)
		{
			op_pb(ps);
			if (ps->b->size > 1 && ps->b->top->index
				< ps->b->top->next->index)
				op_sb(ps);
			pushed++;
		}
		else
			op_ra(ps);
	}
}

static void	chunk_push(t_ps *ps, int chunk)
{
	int	total;
	int	lo;
	int	hi;

	total = ps->a->size + ps->b->size;
	lo = 0;
	hi = chunk;
	while (lo < total)
	{
		push_one_chunk(ps, lo, hi);
		lo = hi;
		hi += chunk;
		if (hi > total)
			hi = total;
	}
}

static int	get_pos(t_stack *s, t_node *node)
{
	t_node	*cur;
	int		pos;

	cur = s->top;
	pos = 0;
	while (cur && cur != node)
	{
		pos++;
		cur = cur->next;
	}
	return (pos);
}

static void	bring_max_to_top(t_ps *ps)
{
	t_node	*cur;
	t_node	*max;
	int		pos;
	int		size;

	cur = ps->b->top;
	max = ps->b->top;
	while (cur)
	{
		if (cur->index > max->index)
			max = cur;
		cur = cur->next;
	}
	pos = get_pos(ps->b, max);
	size = ps->b->size;
	if (pos <= size / 2)
		while (ps->b->top != max)
			op_rb(ps);
	else
		while (ps->b->top != max)
			op_rrb(ps);
}

void	sort_medium(t_ps *ps)
{
	int	chunk;
	int	n;

	if (stack_is_sorted(ps->a))
		return ;
	n = ps->a->size;
	chunk = (int)(sqrt((double)n) * 3.5) + 3;
	chunk_push(ps, chunk);
	while (ps->b->size > 0)
	{
		bring_max_to_top(ps);
		op_pa(ps);
	}
}
