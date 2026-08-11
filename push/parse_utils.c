/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaurici <dmaurici@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 02:19:29 by dmaurici          #+#    #+#             */
/*   Updated: 2026/08/11 02:19:30 by dmaurici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_valid_int_str(const char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (FALSE);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (FALSE);
	while (s[i])
	{
		if (!ft_isdigit((unsigned char)s[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	in_int_range(const char *s, int *out)
{
	long	val;
	int		sign;
	int		i;

	val = 0;
	sign = 1;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		val = val * 10 + (s[i] - '0');
		if (val * sign > INT_MAX || val * sign < INT_MIN)
			return (FALSE);
		i++;
	}
	*out = (int)(val * sign);
	return (TRUE);
}

t_bool	has_duplicate(t_stack *a, int value)
{
	t_node	*cur;

	cur = a->top;
	while (cur)
	{
		if (cur->value == value)
			return (TRUE);
		cur = cur->next;
	}
	return (FALSE);
}

t_bool	is_flag(const char *s)
{
	if (!s || ft_strlen(s) < 3)
		return (FALSE);
	if (s[0] != '-' || s[1] != '-')
		return (FALSE);
	return (ft_strncmp(s, "--simple", 9) == 0
		|| ft_strncmp(s, "--medium", 9) == 0
		|| ft_strncmp(s, "--complex", 10) == 0
		|| ft_strncmp(s, "--adaptive", 11) == 0
		|| ft_strncmp(s, "--bench", 8) == 0);
}

t_strategy	flag_to_strategy(const char *s)
{
	if (ft_strncmp(s, "--simple", 9) == 0)
		return (SIMPLE);
	if (ft_strncmp(s, "--medium", 9) == 0)
		return (MEDIUM);
	if (ft_strncmp(s, "--complex", 10) == 0)
		return (COMPLEX);
	return (ADAPTIVE);
}
