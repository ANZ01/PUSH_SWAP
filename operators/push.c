/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:46:50 by dmaurici          #+#    #+#             */
/*   Updated: 2026/07/02 16:21:45 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_node(t_stack **from, t_stack **to)
{
	t_stack	*node;

	if (!from || !*from || !to)
		return (0);
	node = *from;
	*from = node->next;
	if (*from)
		(*from)->prev = NULL;
	node->next = *to;
	node->prev = NULL;
	if (*to)
		(*to)->prev = node;
	*to = node;
	return (1);
}

void	pa(t_data *data, int print)
{
	if (!data)
		return ;
	if (push_node(&data->b, &data->a))
	{
		if (print)
		{
			data->bench.pa++;
			data->bench.total++;
			ft_printf("pa\n");
		}
	}
}

void	pb(t_data *data, int print)
{
	if (!data)
		return ;
	if (push_node(&data->a, &data->b))
	{
		if (print)
		{
			data->bench.pb++;
			data->bench.total++;
			ft_printf("pb\n");
		}
	}
}