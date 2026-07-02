/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 00:43:34 by mariade-          #+#    #+#             */
/*   Updated: 2026/07/02 16:33:12 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h" //libft

typedef struct s_stack
{
    int value;
    int index;
    struct s_stack *next;
    struct s_stack *prev;
}               t_stack;

typedef struct s_bench
{
    int sa;
    int sb;
    int ss;
    int pa;
    int pb;
    int ra;
    int rb;
    int rr;
    int rra;
    int rrb;
    int rrr;
    int total;
}   t_bench;

typedef enum e_strategy
{
    START_ADAPTIVE,
    START_SIMPLE,
    START_MEDIUM,
    START_COMPLEX
}   t_strategy;


typedef struct s_data
{
    t_stack     *a;
    t_stack     *b;
    int         size;/
    int         bench_mode;
    t_strategy  strategy;
    double      disorder;
    t_bench     bench;
}   t_data;

/* INIT / CLEANUP / ERROR */
void	init_data(t_data *data);
void	free_stack(t_stack **stack);
void	free_data(t_data *data);
int		error_exit(t_data *data);


/* Stack utils */

t_stack	*new_node(int value);
void	stack_add_back(t_stack **stack, t_stack *node);
void	stack_add_front(t_stack **stack, t_stack *node);
t_stack	*stack_last(t_stack *stack);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);

/* OPERATORS */
void pa(t_data *data, int print);
#endif
