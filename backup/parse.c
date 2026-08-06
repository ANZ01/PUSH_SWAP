/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 00:00:00 by marvin            #+#    #+#             */
/*   Updated: 2026/06/16 00:00:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Validate and append a single number token to stack a.
*/
static void	parse_token(const char *token, t_ps *ps)
{
	int		val;
	t_node	*node;

	if (!is_valid_int_str(token))
		error_exit(ps);
	if (!in_int_range(token, &val))
		error_exit(ps);
	if (has_duplicate(ps->a, val))
		error_exit(ps);
	node = node_new(val);
	if (!node)
		error_exit(ps);
	stack_push_bottom(ps->a, node);
}

/*
** An argv entry can itself contain several space-separated numbers
** (e.g. the whole thing was passed as one quoted shell argument).
** Split it and feed every piece through parse_token. An argument
** that splits into ZERO tokens (empty string, or all spaces) doesn't
** represent any number at all -- that's invalid input, not something
** to silently skip.
*/
static void	parse_numbers(char *arg, t_ps *ps)
{
	char	**tokens;
	int		i;

	tokens = ft_split(arg, ' ');
	if (!tokens)
		error_exit(ps);
	if (!tokens[0])
	{
		free(tokens);
		error_exit(ps);
	}
	i = 0;
	while (tokens[i])
	{
		parse_token(tokens[i], ps);
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

/*
** Apply one argv entry: either a recognised flag (--bench sets the
** flag directly, the four strategy flags go through flag_to_strategy)
** or one or more numbers to add to stack a.
*/
static void	apply_arg(char *arg, t_ps *ps)
{
	if (is_flag(arg))
	{
		if (ft_strncmp(arg, "--bench", 8) == 0)
			ps->bench_mode = TRUE;
		else
			ps->strategy = flag_to_strategy(arg);
	}
	else
		parse_numbers(arg, ps);
}

/*
** Once every argv entry has been processed: bail out cleanly if no
** numbers were given at all, otherwise rank the stack and measure its
** disorder (must happen before any sorting operation runs).
*/
static t_ps	*finalize_parse(t_ps *ps)
{
	if (ps->a->size == 0)
	{
		ps_free(ps);
		return (NULL);
	}
	normalize(ps->a);
	ps->disorder = compute_disorder(ps->a);
	return (ps);
}

t_ps	*parse_args(int argc, char **argv)
{
	t_ps	*ps;
	int		i;

	if (argc < 2)
		return (NULL);
	ps = ps_new();
	if (!ps)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		apply_arg(argv[i], ps);
		i++;
	}
	return (finalize_parse(ps));
}
