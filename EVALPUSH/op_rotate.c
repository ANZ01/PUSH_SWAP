/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 02:18:29 by dmaurici          #+#    #+#             */
/*   Updated: 2026/08/11 02:18:35 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *s)
{
	t_node	*node;

	if (!s || s->size < 2)
		return ;
	node = stack_pop_top(s);
	stack_push_bottom(s, node);
}

void	op_ra(t_ps *ps)
{
	rotate(ps->a);
	print_op(ps, "ra\n");
	ps->ops.ra++;
	ps->ops.total++;
}

void	op_rb(t_ps *ps)
{
	rotate(ps->b);
	print_op(ps, "rb\n");
	ps->ops.rb++;
	ps->ops.total++;
}

void	op_rr(t_ps *ps)
{
	rotate(ps->a);
	rotate(ps->b);
	print_op(ps, "rr\n");
	ps->ops.rr++;
	ps->ops.total++;
}
