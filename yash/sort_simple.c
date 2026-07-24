/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/06/16 00:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_ps *ps)
{
	if (ps->a->top->index > ps->a->top->next->index)
		op_sa(ps);
}

/*
** Exactly 3 elements: every one of the 6 possible orderings has a
** known 0-2 operation solution using only sa/ra/rra, never touching
** stack b. a/b/c are the ranks (0 = smallest, 2 = largest) of the
** top, middle and bottom node, so this switches on the permutation.
*/
void	sort_three(t_ps *ps)
{
	int	a;
	int	b;
	int	c;

	if (ps->a->size == 2)
		return (sort_two(ps));
	a = ps->a->top->index;
	b = ps->a->top->next->index;
	c = ps->a->top->next->next->index;
	if (a > b && b < c && a < c)
		op_sa(ps);
	else if (a > b && b > c)
	{
		op_sa(ps);
		op_rra(ps);
	}
	else if (a > b && a > c && b < c)
		op_ra(ps);
	else if (a < b && b > c && a < c)
	{
		op_sa(ps);
		op_ra(ps);
	}
	else if (a < b && b > c && a > c)
		op_rra(ps);
}

/*
** Selection sort adapted to the push_swap model, for n >= 6 (4 and 5
** get a cheaper dedicated path in sort_small.c).
**
** Phase 1: n times, find the current minimum of a, rotate it to the
** top the cheap way, then pb it onto b. b fills up in DESCENDING
** order top-to-bottom as a result.
**
** Phase 2: n plain pa's. Since b's pops come out largest-to-smallest,
** a is rebuilt in ASCENDING order top-to-bottom with no positional
** bookkeeping needed on the way back in.
**
** Cost: O(n) rotations per selection x n selections = O(n^2) for
** phase 1; phase 2 is a flat O(n). Total: O(n^2).
*/
static int	try_tiny_cases(t_ps *ps, int n)
{
	if (n == 2)
		sort_two(ps);
	else if (n == 3)
		sort_three(ps);
	else if (n == 4)
		sort_small(ps, 1);
	else if (n == 5)
		sort_small(ps, 2);
	else
		return (0);
	return (1);
}

void	sort_simple(t_ps *ps)
{
	int	n;
	int	i;
	int	pos;

	if (stack_is_sorted(ps->a))
		return ;
	n = ps->a->size;
	if (try_tiny_cases(ps, n))
		return ;
	i = 0;
	while (i < n)
	{
		pos = find_min_pos(ps->a);
		rotate_to_top(ps, pos);
		op_pb(ps);
		i++;
	}
	i = 0;
	while (i < n)
	{
		op_pa(ps);
		i++;
	}
}
