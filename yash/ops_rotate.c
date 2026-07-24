/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/06/16 00:00:00 by marvin           ###   ########.fr       */
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
	ft_putstr_fd("ra\n", 1);
	ps->ops.ra++;
	ps->ops.total++;
}

void	op_rb(t_ps *ps)
{
	rotate(ps->b);
	ft_putstr_fd("rb\n", 1);
	ps->ops.rb++;
	ps->ops.total++;
}

void	op_rr(t_ps *ps)
{
	rotate(ps->a);
	rotate(ps->b);
	ft_putstr_fd("rr\n", 1);
	ps->ops.rr++;
	ps->ops.total++;
}
