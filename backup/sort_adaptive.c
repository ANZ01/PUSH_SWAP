/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 10:04:35 by marvin            #+#    #+#             */
/*   Updated: 2026/08/06 10:04:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Strategy selection:
**   n <= 3              -> sort_three  (trivial)
**   n <= 5              -> sort_simple (brute force)
**   n <= 100            -> sort_medium (chunk + cost insert) ~700-900 ops
**   n > 100, dis < 0.2 -> sort_medium (nearly sorted, chunk is better)
**   n > 100             -> sort_complex (radix, fixed 6784 for n=500)
*/

void	sort_adaptive(t_ps *ps)
{
	if (stack_is_sorted(ps->a))
		return ;
	if (ps->a->size <= 3)
		sort_three(ps);
	else if (ps->a->size <= 5)
		sort_simple(ps);
	else if (ps->a->size <= 100)
		sort_medium(ps);
	else if (ps->disorder < 0.2)
		sort_medium(ps);
	else
		sort_complex(ps);
}
