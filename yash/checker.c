/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/06/16 00:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Read a single '\n'-terminated line from stdin (no trailing '\n'
** kept). Returns NULL once nothing more can be read (EOF).
*/
static char	*read_line(void)
{
	char	*line;
	char	buf[2];
	int		i;
	int		ret;

	line = ft_calloc(256, 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < 255)
	{
		ret = read(0, buf, 1);
		if (ret <= 0 || buf[0] == '\n')
			break ;
		line[i++] = buf[0];
	}
	if (i == 0 && ret <= 0)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

static void	read_and_apply(t_ps *ps)
{
	char	*line;

	line = read_line();
	while (line)
	{
		apply_op(ps, line);
		free(line);
		line = read_line();
	}
}

int	main(int argc, char **argv)
{
	t_ps	*ps;

	if (argc < 2)
		return (0);
	ps = parse_args(argc, argv);
	if (!ps)
		return (0);
	read_and_apply(ps);
	if (stack_is_sorted(ps->a) && ps->b->size == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ps_free(ps);
	return (0);
}
