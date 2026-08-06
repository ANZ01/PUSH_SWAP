/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/06/16 00:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Every op_* function calls this instead of ft_putstr_fd directly, so
** there is exactly one place in the whole project responsible for
** actually printing an operation's name -- one choke point instead
** of 11 separate call sites across 4 files.
*/
void	print_op(t_ps *ps, char *str)
{
	(void)ps;
	ft_putstr_fd(str, 1);
}

/*
** Prints just the running operation total, as a bare number followed
** by a newline, to whichever fd the caller wants. Shared by
** bench_print (which prefixes it with "[bench] total_ops:  " on
** stderr) so the "print a number + newline" logic only exists once,
** instead of being duplicated everywhere a total needs printing.
*/
void	print_total_ops(t_ps *ps, int fd)
{
	ft_putnbr_fd(ps->ops.total, fd);
	ft_putstr_fd("\n", fd);
}
