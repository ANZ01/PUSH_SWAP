/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 02:21:17 by dmaurici          #+#    #+#             */
/*   Updated: 2026/08/11 02:23:48 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_ps *ps)
{
	if (stack_is_sorted(ps->a))
		return ;
	if (ps->a->size <= 3)
		sort_three(ps);
	else if (ps->disorder < 0.2)
		sort_simple(ps);
	else if (ps->disorder < 0.5)
		sort_medium(ps);
	else
		sort_complex(ps);
}
