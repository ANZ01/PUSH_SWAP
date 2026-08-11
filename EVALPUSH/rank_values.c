/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 02:20:34 by dmaurici          #+#    #+#             */
/*   Updated: 2026/08/11 02:23:42 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
