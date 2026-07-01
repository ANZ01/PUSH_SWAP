/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:40:09 by dmaurici          #+#    #+#             */
/*   Updated: 2026/06/23 11:26:34 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_stack_op(t_stack *first_node, t_stack *second_node)
{
	int				temp_v;
	unsigned int	temp_i;
	
	if (!first_node || !second_node)
		return	;
	temp_i = first_node->index;
	temp_v = first_node->value;
	first_node->index = second_node->index;
	first_node->value = second_node->value;
	second_node->index = temp_i;
	second_node->value = temp_v;
}
void	sa(t_stack *first_node, t_stack *second_node, t_bench *bench)
{
	swap_stack_op(first_node,second_node);
	bench->sa++;
	ft_printf("sa\n");
}
void	sb(t_stack *first_node, t_stack *second_node, t_bench *bench)
{
	swap_stack_op(first_node,second_node);
	bench->sb++;
	ft_printf("sb\n");
}
void	ss(t_stack *first_node_a, t_stack *second_node_a, t_stack *first_node_b, t_stack *second_node_b, t_bench *bench)
{
	swap_stack_op(first_node_a, second_node_a);
	swap_stack_op(first_node_b, second_node_b);
	bench->ss++;
	ft_printf("ss\n");
}