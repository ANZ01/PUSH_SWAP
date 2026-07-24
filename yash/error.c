/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 12:14:09 by marvin            #+#    #+#             */
/*   Updated: 2026/06/15 12:14:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Prints "Error\n" to stderr using ft_putstr_fd,
** frees all memory and exits with status 1.
*/

void	error_exit(t_ps *ps)
{
	ft_putstr_fd("Error\n", 2);
	if (ps)
		ps_free(ps);
	exit(1);
}
