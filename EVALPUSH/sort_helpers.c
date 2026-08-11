/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 02:21:29 by dmaurici          #+#    #+#             */
/*   Updated: 2026/08/11 02:24:01 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
