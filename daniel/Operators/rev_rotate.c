#include "push_swap.h"

static int	reverse_rotate_stack(t_stack **stack)
{
	t_stack *last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	last = stack_last(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = (*stack);
	(*stack)->prev = last;
	(*stack) = last;
	return (1);
}
void	rra(t_data *data, int print)
{
	if (!data)
		return ;
	if (reverse_rotate_stack(&data->a))
	{
		if (print)
		{
			data->bench.rra++;
			data->bench.total++;
			ft_printf("rra\n");
		}
	}
}
void	rrb(t_data *data, int print)
{
	if (!data)
		return ;
	if (reverse_rotate_stack(&data->b))
	{
		if (print)
		{
			data->bench.rrb++;
			data->bench.total++;
			ft_printf("rrb\n");
		}
	}
}
void	rrr(t_data *data, int print)
{
	int	rev_a;
	int	rev_b;

	if (!data)
		return ;
	rev_a = reverse_rotate_stack(&data->a);
	rev_b = reverse_rotate_stack(&data->b);
	if (rev_a || rev_b)
	{
		if (print)
		{
			data->bench.rrr++;
			data->bench.total++;
			ft_printf("rrr\n");
		}
	}
}
