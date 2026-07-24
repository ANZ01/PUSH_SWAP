#include "push_swap.h"

static int	push_stack(t_stack **from, t_stack **to)
{
	t_stack *temp;

	if (!from || !to || !*from)
		return (0);
	temp = *from;
	*from = temp->next;
	if (*from)
		(*from)->prev = NULL;
	temp->next = *to;
	temp->prev = NULL;
	if (*to)
		(*to)->prev = temp;
	*to = temp;
	return (1);
}
void	pa(t_data *data,int print)
{
	if (!data)
		return ;
	if (push_stack(&data->b, &data->a))
	{
		if (print)
		{
			data->bench.pa++;
			data->bench.total++;
			ft_printf("pa\n");
		}
	}
}
void	pb(t_data *data,int print)
{
	if (!data)
		return ;
	if (push_stack(&data->a, &data->b))
	{
		if (print)
		{
			data->bench.pb++;
			data->bench.total++;
			ft_printf("pb\n");
		}
	}
}
