/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/06/16 00:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_pa(t_ps *ps)
{
	t_node	*node;

	if (!ps->b || ps->b->size == 0)
		return ;
	node = stack_pop_top(ps->b);
	stack_push_top(ps->a, node);
	ft_putstr_fd("pa\n", 1);
	ps->ops.pa++;
	ps->ops.total++;
}

void	op_pb(t_ps *ps)
{
	t_node	*node;

	if (!ps->a || ps->a->size == 0)
		return ;
	node = stack_pop_top(ps->a);
	stack_push_top(ps->b, node);
	ft_putstr_fd("pb\n", 1);
	ps->ops.pb++;
	ps->ops.total++;
}
