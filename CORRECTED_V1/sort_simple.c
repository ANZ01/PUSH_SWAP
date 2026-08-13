/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 02:21:39 by dmaurici          #+#    #+#             */
/*   Updated: 2026/08/13 23:04:37 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_ps *ps)
{
	if (ps->a->top->index > ps->a->top->next->index)
		op_sa(ps);
}

void	sort_three(t_ps *ps)
{
	int	a;
	int	b;
	int	c;

	if (ps->a->size == 2)
		return (sort_two(ps));
	a = ps->a->top->index;
	b = ps->a->top->next->index;
	c = ps->a->top->next->next->index;
	if (a > b && b < c && a < c)
		op_sa(ps);
	else if (a > b && b > c)
	{
		op_sa(ps);
		op_rra(ps);
	}
	else if (a > b && a > c && b < c)
		op_ra(ps);
	else if (a < b && b > c && a < c)
	{
		op_sa(ps);
		op_ra(ps);
	}
	else if (a < b && b > c && a > c)
		op_rra(ps);
}

static int	try_tiny_cases(t_ps *ps, int n)
{
	if (n == 2)
		sort_two(ps);
	else if (n == 3)
		sort_three(ps);
	else if (n == 4)
		sort_small(ps, 1);
	else if (n == 5)
		sort_small(ps, 2);
	else
		return (0);
	return (1);
}

void	sort_simple(t_ps *ps)
{
	int	n;
	int	i;
	int	pos;

	if (stack_is_sorted(ps->a))
		return ;
	n = ps->a->size;
	if (try_tiny_cases(ps, n))
		return ;
	i = 0;
	while (i < n)
	{
		pos = find_min_pos(ps->a);
		rotate_to_top(ps, pos);
		op_pb(ps);
		i++;
	}
	i = 0;
	while (i < n)
	{
		op_pa(ps);
		i++;
	}
}
