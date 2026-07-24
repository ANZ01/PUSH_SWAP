/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/06/16 00:00:00 by marvin           ###   ########.fr       */
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
	ft_putstr_fd("sa\n", 1);
	ps->ops.sa++;
	ps->ops.total++;
}

void	op_sb(t_ps *ps)
{
	swap_top(ps->b);
	ft_putstr_fd("sb\n", 1);
	ps->ops.sb++;
	ps->ops.total++;
}

void	op_ss(t_ps *ps)
{
	swap_top(ps->a);
	swap_top(ps->b);
	ft_putstr_fd("ss\n", 1);
	ps->ops.ss++;
	ps->ops.total++;
}
