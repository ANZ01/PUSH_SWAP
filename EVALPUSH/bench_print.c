/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 02:15:46 by dmaurici          #+#    #+#             */
/*   Updated: 2026/08/11 02:34:25 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_strategy(t_ps *ps)
{
	if (ps->strategy == SIMPLE)
		ft_putstr_fd("[bench] strategy:   Simple / O(n^2)\n", 2);
	else if (ps->strategy == MEDIUM)
		ft_putstr_fd("[bench] strategy:   Medium / O(n*sqrt(n))\n", 2);
	else if (ps->strategy == COMPLEX)
		ft_putstr_fd("[bench] strategy:   Complex / O(n log n)\n", 2);
	else
		ft_putstr_fd("[bench] strategy:   Adaptive\n", 2);
}

static void	putnbr_fd(int n, int fd)
{
	ft_putnbr_fd(n, fd);
	ft_putstr_fd(" ", fd);
}

static void	print_ops_line1(t_ps *ps)
{
	ft_putstr_fd("[bench] sa: ", 2);
	putnbr_fd(ps->ops.sa, 2);
	ft_putstr_fd("sb: ", 2);
	putnbr_fd(ps->ops.sb, 2);
	ft_putstr_fd("ss: ", 2);
	putnbr_fd(ps->ops.ss, 2);
	ft_putstr_fd("pa: ", 2);
	putnbr_fd(ps->ops.pa, 2);
	ft_putstr_fd("pb: ", 2);
	ft_putnbr_fd(ps->ops.pb, 2);
	ft_putstr_fd("\n", 2);
}

static void	print_ops_line2(t_ps *ps)
{
	ft_putstr_fd("[bench] ra: ", 2);
	putnbr_fd(ps->ops.ra, 2);
	ft_putstr_fd("rb: ", 2);
	putnbr_fd(ps->ops.rb, 2);
	ft_putstr_fd("rr: ", 2);
	putnbr_fd(ps->ops.rr, 2);
	ft_putstr_fd("rra: ", 2);
	putnbr_fd(ps->ops.rra, 2);
	ft_putstr_fd("rrb: ", 2);
	putnbr_fd(ps->ops.rrb, 2);
	ft_putstr_fd("rrr: ", 2);
	ft_putnbr_fd(ps->ops.rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	bench_print(t_ps *ps)
{
	int	disorder_pct;
	int	disorder_dec;

	disorder_pct = (int)(ps->disorder * 100);
	disorder_dec = (int)(ps->disorder * 10000) % 100;
	ft_putstr_fd("[bench] disorder:   ", 2);
	ft_putnbr_fd(disorder_pct, 2);
	ft_putstr_fd(".", 2);
	if (disorder_dec < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(disorder_dec, 2);
	ft_putstr_fd("%\n", 2);
	print_strategy(ps);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	print_total_ops(ps, 2);
	print_ops_line1(ps);
	print_ops_line2(ps);
}
