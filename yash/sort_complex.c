/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/06/16 00:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Returns number of bits needed to represent (n - 1).
** e.g. n=100 -> indices 0..99 -> 7 bits (2^7=128 > 99)
**      n=500 -> indices 0..499 -> 9 bits (2^9=512 > 499)
** This is the exact number of radix passes needed.
*/

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

/*
** One LSD radix pass for a given bit position.
** Elements with bit=0 go to b (pb), bit=1 stay via rotate (ra).
** Then push all of b back to a (pa).
** After all bits processed, a is sorted ascending.
*/

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
	size = ps->a->size;
	bits = bits_needed(size);
	bit = 0;
	while (bit < bits)
	{
		radix_pass(ps, bit, size);
		bit++;
	}
}
