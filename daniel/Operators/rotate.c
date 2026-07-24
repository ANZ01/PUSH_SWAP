#include "push_swap.h"

static int	rotate_stack(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	last = stack_last(*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	return (1);
}

void	ra(t_data *data, int print)
{
	if (!data)
		return ;
	if (rotate_stack(&data->a))
	{
		if (print)
		{
			data->bench.ra++;
			data->bench.total++;
			ft_printf("ra\n");
		}
	}
}
void	rb(t_data *data, int print)
{
	if (!data)
		return ;
	if (rotate_stack(&data->b))
	{
		if (print)
		{
			data->bench.rb++;
			data->bench.total++;
			ft_printf("rb\n");
		}
	}
}
void	rr(t_data *data, int print)
{
	int	rotated_a;
	int	rotated_b;

	if (!data)
		return ;
	rotated_a = rotate_stack(&data->a);
	rotated_b = rotate_stack(&data->b);
	if (rotated_a || rotated_b)
	{
		if (print)
		{
			data->bench.rr++;
			data->bench.total++;
			ft_printf("rr\n");
		}
	}
}
