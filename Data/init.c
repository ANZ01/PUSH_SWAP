/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:09:13 by dmaurici          #+#    #+#             */
/*   Updated: 2026/07/02 15:09:13 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_daniel.h"

void	init_data(t_data *data)
{
	data->a = NULL;
	data->b = NULL;
	data->size = 0;
	data->bench_mode = 0;
	data->strategy = STRAT_ADAPTIVE;
	data->disorder = 0.0;
	data->bench.sa = 0;
	data->bench.sb = 0;
	data->bench.ss = 0;
	data->bench.pa = 0;
	data->bench.pb = 0;
	data->bench.ra = 0;
	data->bench.rb = 0;
	data->bench.rr = 0;
	data->bench.rra = 0;
	data->bench.rrb = 0;
	data->bench.rrr = 0;
	data->bench.total = 0;
}