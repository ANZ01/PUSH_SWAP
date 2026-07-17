#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	stack_add_back(t_stack **stack, t_stack *node)
{
	t_stack	*last;

	if (!stack || !node)
		return ;
	node->next = NULL;
	if (!*stack)
	{
		node->prev = NULL;
		*stack = node;
		return ;
	}
	last = stack_last(*stack);
	last->next = node;
	node->prev = last;
}

void	stack_add_front(t_stack **stack, t_stack *node)
{
	if (!stack || !node)
		return ;
	node->prev = NULL;
	node->next = *stack;
	if (*stack)
		(*stack)->prev = node;
	*stack = node;
}

