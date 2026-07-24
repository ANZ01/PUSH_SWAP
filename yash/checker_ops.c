/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/06/16 00:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	try_basic_op(t_ps *ps, char *op)
{
	if (ft_strncmp(op, "sa", 3) == 0)
		op_sa(ps);
	else if (ft_strncmp(op, "sb", 3) == 0)
		op_sb(ps);
	else if (ft_strncmp(op, "ss", 3) == 0)
		op_ss(ps);
	else if (ft_strncmp(op, "pa", 3) == 0)
		op_pa(ps);
	else if (ft_strncmp(op, "pb", 3) == 0)
		op_pb(ps);
	else
		return (0);
	return (1);
}

static int	try_rotate_op(t_ps *ps, char *op)
{
	if (ft_strncmp(op, "ra", 3) == 0)
		op_ra(ps);
	else if (ft_strncmp(op, "rb", 3) == 0)
		op_rb(ps);
	else if (ft_strncmp(op, "rr", 3) == 0)
		op_rr(ps);
	else if (ft_strncmp(op, "rra", 4) == 0)
		op_rra(ps);
	else if (ft_strncmp(op, "rrb", 4) == 0)
		op_rrb(ps);
	else if (ft_strncmp(op, "rrr", 4) == 0)
		op_rrr(ps);
	else
		return (0);
	return (1);
}

/*
** Apply one instruction line read from stdin. Any string that isn't
** one of the 11 valid operations is a malformed instruction stream:
** Error, per the subject.
*/
void	apply_op(t_ps *ps, char *op)
{
	if (try_basic_op(ps, op))
		return ;
	if (try_rotate_op(ps, op))
		return ;
	free(op);
	error_exit(ps);
}
