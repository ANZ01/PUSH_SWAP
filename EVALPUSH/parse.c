/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 02:19:35 by dmaurici          #+#    #+#             */
/*   Updated: 2026/08/11 04:12:33 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	parse_token(const char *token, t_ps *ps)
{
	int		val;
	t_node	*node;

	if (!is_valid_int_str(token))
		return (FALSE);
	if (!in_int_range(token, &val))
		return (FALSE);
	if (has_duplicate(ps->a, val))
		return (FALSE);
	node = node_new(val);
	if (!node)
		return (FALSE);
	stack_push_bottom(ps->a, node);
	return (TRUE);
}

static void	parse_numbers(char *arg, t_ps *ps)
{
	char	**tokens;
	int		i;

	tokens = ft_split(arg, ' ');
	if (!tokens || !tokens[0])
	{
		free_tokens(tokens);
		error_exit(ps);
	}
	i = 0;
	while (tokens[i])
	{
		if (!parse_token(tokens[i], ps))
		{
			free_tokens(tokens);
			error_exit(ps);
		}
		i++;
	}
	free_tokens(tokens);
}

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
