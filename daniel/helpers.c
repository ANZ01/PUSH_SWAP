#include "push_swap.h"

int find_min_index(t_stack *stack)
{
	int	min;

	if (!stack)
		return (-1);
	min = stack->index;
	while (stack)
	{
		if (min > stack->index)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}
int find_max_index(t_stack *stack)
{
		int	max;

	if (!stack)
		return (-1);
	max = stack->index;
	while (stack)
	{
		if (max < stack->index)
			max = stack->index;
		stack = stack->next;
	}
	return (max);
}

int	find_pos_by_index(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (index == stack->index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

void	move_index_to_top_a(t_data *data, int index)
{
	int	pos;
	int	size;

	if (!data || !data->a)
		return ;
	pos = find_pos_by_index(data->a, index);
	if (pos == -1)
		return ;
	size = stack_size(data->a);
	if (pos <= size / 2)
	{
		while (data->a->index != index)
			ra(data, 1);
	}
	else
	{
		while (data->a->index != index)
			rra(data, 1);
	}
}
void	move_index_to_top_b(t_data *data, int index)
{
	int	pos;
	int	size;

	if (!data || !data->b)
		return ;
	pos = find_pos_by_index(data->b, index);
	if (pos == -1)
		return ;
	size = stack_size(data->b);
	if (pos <= size / 2)
	{
		while (data->b->index != index)
			rb(data, 1);
	}
	else
	{
		while (data->b->index != index)
			rrb(data, 1);
	}
}