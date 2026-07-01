/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariade- <mariade-student.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 00:43:34 by mariade-          #+#    #+#             */
/*   Updated: 2026/06/23 00:43:35 by mariade-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "Libft/libft.h"

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
    int strategy;
    int total;
    float   disorder;
}               t_bench;

#endif