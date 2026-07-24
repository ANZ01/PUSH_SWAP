#include "push_swap.h"

static int	swap_stack(t_stack **stack)
{
	t_stack *first;
	t_stack *second;
	t_stack *third;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	second = first->next;
	third = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = third;
	if (third)
		third->prev = first;
	*stack = second;
	return (1);
}

void	sa(t_data *data, int print)
{
	if (!data)
		return ;
	if (swap_stack(&data->a))
	{
		if (print)
		{
			data->bench.sa++;
			data->bench.total++;
			ft_printf("sa\n");
		}
	}
}
void	sb(t_data *data, int print)
{
	if (!data)
		return ;
	if (swap_stack(&data->b))
	{
		if (print)
		{
			data->bench.sb++;
			data->bench.total++;
			ft_printf("sb\n");
		}
	}
}

void	ss(t_data *data, int print)
{
	int	swapped_a;
	int swapped_b;

	if (!data)
		return ;
	swapped_a = swap_stack(&data->a);
	swapped_b = swap_stack(&data->b);
	if (swapped_a || swapped_b)
	{
		if (print)
		{
			data->bench.ss++;
			data->bench.total++;
			ft_printf("ss\n");
		}
	}
}
