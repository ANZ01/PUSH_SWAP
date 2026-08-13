/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 02:12:55 by dmaurici          #+#    #+#             */
/*   Updated: 2026/08/11 02:19:01 by dmaurici         ###   ########.fr       */
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
	print_op(ps, "pa\n");
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
	print_op(ps, "pb\n");
	ps->ops.pb++;
	ps->ops.total++;
}
