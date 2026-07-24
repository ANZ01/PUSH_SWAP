/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/06/16 00:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

/*
** Push every element belonging to the current chunk [lo, hi) from a
** to b, rotating a to skip past elements that don't belong yet.
*/
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

/*
** Chunk sort: split the index range [0, total) into chunks of size
** `chunk` and push each chunk from a to b in turn.
*/
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

/*
** Find the current maximum of b and rotate it to the top, the cheap
** direction. Repeatedly taking the maximum out of b and pa'ing it
** rebuilds a in ascending order top-to-bottom: the first value pulled
** is the largest remaining, so it ends up deepest in a; the last
** value pulled is the smallest remaining, so it ends up on top.
*/
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

/*
** O(n*sqrt(n)) chunk sort. sqrt(n) chunks, each of size ~sqrt(n):
** pushing every chunk costs O(n) rotations total across all chunks,
** and pulling everything back via bring_max_to_top costs O(sqrt(n))
** per element for n elements = O(n*sqrt(n)). Total: O(n*sqrt(n)).
*/
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
