/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 02:15:37 by dmaurici          #+#    #+#             */
/*   Updated: 2026/08/11 02:34:20 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_strategy(t_ps *ps)
{
	if (ps->strategy == SIMPLE)
		sort_simple(ps);
	else if (ps->strategy == MEDIUM)
		sort_medium(ps);
	else if (ps->strategy == COMPLEX)
		sort_complex(ps);
	else
		sort_adaptive(ps);
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	ps = parse_args(argc, argv);
	if (!ps)
		return (0);
	if (stack_is_sorted(ps->a))
	{
		if (ps->bench_mode)
			bench_print(ps);
		ps_free(ps);
		return (0);
	}
	run_strategy(ps);
	if (ps->bench_mode)
		bench_print(ps);
	ps_free(ps);
	return (0);
}
