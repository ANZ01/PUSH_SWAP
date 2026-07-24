/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 16:48:18 by dmaurici          #+#    #+#             */
/*   Updated: 2026/07/02 16:48:18 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp_stack;

	if (!stack)
		return ;
	while (*stack)
	{
		temp_stack = (*stack)->next;
		free(*stack);
		*stack = temp_stack;
	}
}
void free_data(t_data *data)
{
	if(!data)
		return ;
	free_stack(&data->a);
	free_stack(&data->b);
}