/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/07/22 15:55:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Position (0 = top) of the node holding the smallest index in the
** stack. Shared by sort_simple (selection loop) and sort_small
** (pushing the current minimum out first).
*/
int	find_min_pos(t_stack *s)
{
	t_node	*cur;
	t_node	*min;
	int		pos;
	int		min_pos;

	cur = s->top;
	min = s->top;
	pos = 0;
	min_pos = 0;
	while (cur)
	{
		if (cur->index < min->index)
		{
			min = cur;
			min_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (min_pos);
}

/*
** Rotate stack a so the node currently `pos` positions from the top
** ends up on top, always choosing the cheaper direction.
*/
void	rotate_to_top(t_ps *ps, int pos)
{
	int	size;

	size = ps->a->size;
	if (pos <= size - pos)
	{
		while (pos-- > 0)
			op_ra(ps);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			op_rra(ps);
	}
}