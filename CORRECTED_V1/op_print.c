/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 02:12:50 by dmaurici          #+#    #+#             */
/*   Updated: 2026/08/11 02:22:57 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_op(t_ps *ps, char *str)
{
	(void)ps;
	ft_putstr_fd(str, 1);
}

void	print_total_ops(t_ps *ps, int fd)
{
	ft_putnbr_fd(ps->ops.total, fd);
	ft_putstr_fd("\n", fd);
}
