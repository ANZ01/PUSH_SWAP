/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   measure_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 10:02:35 by marvin            #+#    #+#             */
/*   Updated: 2026/08/06 10:02:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Computes the disorder of stack a as a value between 0.0 and 1.0.
**
** Method (exactly as the subject specifies): look at every pair (i, j)
** where i comes before j in the stack. If a[i] > a[j], that pair counts
** as a "mistake". disorder = mistakes / total_pairs.
**
** disorder == 0.0 -> already sorted
** disorder == 1.0 -> worst possible order (fully reversed)
**
** We compare normalized indices (0..n-1), not raw values, so the ratio
** is clean regardless of the actual numbers involved. This MUST be
** called before any sorting moves are made.
*/
double	compute_disorder(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	double	mistakes;
	double	total_pairs;

	if (!a || a->size <= 1)
		return (0.0);
	mistakes = 0.0;
	total_pairs = 0.0;
	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs += 1.0;
			if (i->index > j->index)
				mistakes += 1.0;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes / total_pairs);
}
