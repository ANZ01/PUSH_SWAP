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
	if (!data)
		return ;
	if (find_pos_by_index())
}