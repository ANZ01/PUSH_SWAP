/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 02:21:46 by dmaurici          #+#    #+#             */
/*   Updated: 2026/08/11 02:24:38 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_ps *ps, int pushes)
{
	int	i;

	i = 0;
	while (i < pushes)
	{
		rotate_to_top(ps, find_min_pos(ps->a));
		op_pb(ps);
		i++;
	}
	sort_three(ps);
	while (i-- > 0)
		op_pa(ps);
}
