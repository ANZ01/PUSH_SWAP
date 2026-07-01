/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 11:46:50 by dmaurici          #+#    #+#             */
/*   Updated: 2026/06/23 12:41:44 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_stack_op(t_stack **first_list, t_stack **second_list)
{
	int				temp_v;
	int				temp_i;
	unsigned int	i;

	if ((!first_list || !*first_list) || (!second_list || !*second_list))
		return ;
	i = 0;
	while (i < 2)
	{
		temp_i = *first_list->index;
		temp_v = *first_list->value;
		*first_list->index = *second_list->index;
		*first_list->value = *second_list->value;
		*second_list->index = temp_i;
		*second_list->value = temp_v;
		*first_list = *first_list->next;
		*second_list = second_list->next;
		i++;
	}
}

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	push_stack_op(a, b);
	bench->pa++;
	ft_printf("pa\n");
}
void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	push_stack_op(b, a);
	bench->pb++;
	ft_printf("pb\n");
}