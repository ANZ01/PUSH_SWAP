/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariade- <mariade-student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 22:12:52 by mariade-          #+#    #+#             */
/*   Updated: 2026/06/23 00:40:09 by mariade-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    rotate_stack_op(t_stack **stack)
{
    t_stack *cur_node;
    int     temp_v;
    int     temp_i;

    if (!stack || !*stack)
        return ;
    cur_node = *stack;
    while (cur_node->next != NULL)
    {
        temp_v = cur_node->value;
        cur_node->value = cur_node->next->value;
        cur_node->next->value = temp_v;
        temp_i = cur_node->index;
        cur_node->index = cur_node->next->index;
        cur_node->next->index = temp_i;
        cur_node = cur_node->next;
    }
}

void    ra(t_stack **a, t_bench *bench)
{
    rotate_stack_op(a);
    bench->ra++;
    ft_printf("ra\n");
}

void    rb(t_stack **b, t_bench *bench)
{
    rotate_stack_op(b);
    bench->rb++;
    ft_printf("rb\n");
}

void    rr(t_stack **a, t_stack **b, t_bench *bench)
{
    rotate_stack_op(a);
    rotate_stack_op(b);
    bench->rr++;
    ft_printf("rr\n");
}
