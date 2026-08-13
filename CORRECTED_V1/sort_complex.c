/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 02:21:24 by dmaurici          #+#    #+#             */
/*   Updated: 2026/08/13 23:11:44 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bits_needed(int n)
{
	int	bits;

	bits = 0;
	n--;
	while (n > 0)
	{
		n >>= 1;
		bits++;
	}
	return (bits);
}

static void	radix_pass(t_ps *ps, int bit, int size)
{
	int	i;
	int	pushed;

	i = 0;
	pushed = 0;
	while (i < size)
	{
		if ((ps->a->top->index >> bit) & 1)
			op_ra(ps);
		else
		{
			op_pb(ps);
			pushed++;
		}
		i++;
	}
	while (pushed > 0)
	{
		op_pa(ps);
		pushed--;
	}
}

void	sort_complex(t_ps *ps)
{
	int	bits;
	int	bit;
	int	size;

	if (stack_is_sorted(ps->a))
		return ;
	if (ps->a->size <= 5)
	{
		sort_simple(ps);
		return ;
	}
	size = ps->a->size;
	bits = bits_needed(size);
	bit = 0;
	while (bit < bits)
	{
		radix_pass(ps, bit, size);
		bit++;
	}
}
