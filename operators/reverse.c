/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 22:13:01 by mariade-          #+#    #+#             */
/*   Updated: 2026/06/23 11:25:47 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    reverse_stack_op(t_stack **stack)
{
    t_stack *cur_node;
    int     temp_v;
    int     temp_i;

    if (!stack || !*stack)
        return ;
    cur_node = ft_lstlast(*stack);
    while (cur_node->prev != NULL)
    {
        temp_v = cur_node->value;
        cur_node->value = cur_node->prev->value;
        cur_node->prev->value = temp_v;
        temp_i = cur_node->index;
        cur_node->index = cur_node->prev->index;
        cur_node->prev->index = temp_i;
        cur_node = cur_node->prev;
    }
}

void    rra_op(t_stack **a, t_bench *bench)
{
    reverse_stack_op(a);
    bench->rra++;
    ft_printf("rra\n");
}

void    rrb(t_stack **b, t_bench *bench)
{
    reverse_stack_op(b);
    bench->rrb++;
    ft_printf("rrb\n");
}

void    rrr(t_stack **a, t_stack **b, t_bench *bench)
{
    reverse_stack_op(a);
    reverse_stack_op(b);
    bench->rrr++;
    ft_printf("rrr\n");
}