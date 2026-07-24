/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/06/16 00:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** 4 or 5 elements: push the current minimum of a to b (rotating it to
** the top the cheap way first) `pushes` times, shrinking the problem
** to size 3, solve that with sort_three, then pull the pushed
** element(s) back with pa (the LAST one pushed was the largest of the
** pushed group, so the FIRST one pulled back lands correctly on top).
**
** This is what closes the gap with a reference implementation's op
** counts for these small, very common sizes, instead of running the
** full O(n^2) selection-sort machinery on a case that has a much
** cheaper dedicated path.
*/
void	sort_small(t_ps *ps, int pushes)
{
	int	i;

	i = 0;
	while (i < pushes)
	{
		rotate_to_top(ps, find_min_pos(ps->a));
		op_pb(ps);
		i++;
	}
	sort_three(ps);
	while (i-- > 0)
		op_pa(ps);
}
