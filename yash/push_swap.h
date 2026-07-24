/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/07/22 15:54:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}	t_bool;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}	t_bench;

typedef struct s_ps
{
	t_stack		*a;
	t_stack		*b;
	t_strategy	strategy;
	t_bool		bench_mode;
	double		disorder;
	t_bench		ops;
}	t_ps;

/* stack.c */
t_node		*node_new(int value);
t_stack		*stack_new(void);
void		stack_free(t_stack *s);
t_ps		*ps_new(void);
void		ps_free(t_ps *ps);

/* stack_utils.c */
void		stack_push_top(t_stack *s, t_node *node);
void		stack_push_bottom(t_stack *s, t_node *node);
t_node		*stack_pop_top(t_stack *s);
t_bool		stack_is_sorted(t_stack *s);
t_node		*stack_min(t_stack *s);

/* parse.c */
t_ps		*parse_args(int argc, char **argv);

/* parse_utils.c */
t_bool		is_valid_int_str(const char *s);
t_bool		in_int_range(const char *s, int *out);
t_bool		has_duplicate(t_stack *a, int value);
t_bool		is_flag(const char *s);
t_strategy	flag_to_strategy(const char *s);

/* normalize.c */
void		normalize(t_stack *a);

/* error.c */
void		error_exit(t_ps *ps);

/* disorder.c */
double		compute_disorder(t_stack *a);

/* ops_swap.c */
void		op_sa(t_ps *ps);
void		op_sb(t_ps *ps);
void		op_ss(t_ps *ps);

/* ops_push.c */
void		op_pa(t_ps *ps);
void		op_pb(t_ps *ps);

/* ops_rotate.c */
void		op_ra(t_ps *ps);
void		op_rb(t_ps *ps);
void		op_rr(t_ps *ps);

/* ops_reverse.c */
void		op_rra(t_ps *ps);
void		op_rrb(t_ps *ps);
void		op_rrr(t_ps *ps);

/* sort_simple.c */
void		sort_simple(t_ps *ps);
void		sort_three(t_ps *ps);

/* sort_utils.c */
int			find_min_pos(t_stack *s);
void		rotate_to_top(t_ps *ps, int pos);

/* sort_small.c */
void		sort_small(t_ps *ps, int pushes);

/* sort_medium.c */
void		sort_medium(t_ps *ps);

/* sort_complex.c */
void		sort_complex(t_ps *ps);

/* adaptive.c */
void		sort_adaptive(t_ps *ps);

/* bench.c */
void		bench_print(t_ps *ps);

/* checker_ops.c */
void		apply_op(t_ps *ps, char *op);

#endif