/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 10:03:59 by marvin            #+#    #+#             */
/*   Updated: 2026/08/06 10:03:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Finds the node with the smallest value that has not
** been ranked yet. "Unranked" means index == -1.
*/

static t_node	*find_min_unranked(t_stack *a)
{
	t_node	*cur;
	t_node	*min;

	cur = a->top;
	min = NULL;
	while (cur)
	{
		if (cur->index == -1 && (!min || cur->value < min->value))
			min = cur;
		cur = cur->next;
	}
	return (min);
}

/*
** Assigns each node a rank from 0 (smallest) to n-1 (largest).
** Works by repeatedly finding the smallest unranked node.
**
** Why normalize?
**   Algorithms only compare indices — no negatives, no large gaps,
**   just clean integers 0 … n-1. Makes every algorithm simpler.
*/

void	normalize(t_stack *a)
{
	t_node	*min;
	int		rank;

	rank = 0;
	while (rank < a->size)
	{
		min = find_min_unranked(a);
		if (min)
			min->index = rank;
		rank++;
	}
}
