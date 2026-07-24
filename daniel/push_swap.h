/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 00:43:34 by mariade-          #+#    #+#             */
/*   Updated: 2026/07/22 14:15:49 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#define INT_MIN "-2147483648"
#define INT_MAX "2147483647"

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
   - int sb;
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

/* Init / Cleanup / Error */
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


/* Helpers */
int	    find_pos_by_index(t_stack *stack, int index);
int     find_min_index(t_stack *stack);
int     find_max_index(t_stack *stack);
void	move_index_to_top_a(t_data *data, int index);


/* Operators */
void	sa(t_data *data, int print);
void	sb(t_data *data, int print);
void	ss(t_data *data, int print);
void	pa(t_data *data,int print);
void	pb(t_data *data,int print);
void	ra(t_data *data, int print);
void	rb(t_data *data, int print);
void	rr(t_data *data, int print);
void	rra(t_data *data, int print);
void	rrb(t_data *data, int print);
void	rrr(t_data *data, int print);

/* Parser */
int     has_duplicate(t_stack *stack, int value);
int     is_valid_int_string(char *str);
long	ft_atol(const char *str);
int     parse_token(char *token, t_data *data);

#endif