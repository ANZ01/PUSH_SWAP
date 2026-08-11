/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 02:18:21 by dmaurici          #+#    #+#             */
/*   Updated: 2026/08/11 02:18:21 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (!s || s->size < 2)
		return ;
	first = stack_pop_top(s);
	second = stack_pop_top(s);
	stack_push_top(s, first);
	stack_push_top(s, second);
}

void	op_sa(t_ps *ps)
{
	swap_top(ps->a);
	print_op(ps, "sa\n");
	ps->ops.sa++;
	ps->ops.total++;
}

void	op_sb(t_ps *ps)
{
	swap_top(ps->b);
	print_op(ps, "sb\n");
	ps->ops.sb++;
	ps->ops.total++;
}

void	op_ss(t_ps *ps)
{
	swap_top(ps->a);
	swap_top(ps->b);
	print_op(ps, "ss\n");
	ps->ops.ss++;
	ps->ops.total++;
}
