/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakumar <yakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:23:40 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/19 18:12:43 by yakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	result *= sign;
	return (result);
}
/*
 1. convert the initial portion of the string pointed to by str to int
 2. the function first discards as many whitespace characters as necessary
 until the first non-whitespace character is found. Then, starting from this
 character, takes an optional initial plus or minus sign followed by as many
 numerical digits as possible, and interprets them as a numerical value.
 The string can contain additional characters after those that form the integral
 number, which are ignored and have no effect on the behavior of this function.
 3. if the first sequence of non-whitespace characters in str is not a valid
 integral number, or if no such sequence exists because either str is empty
 or it contains only whitespace characters, no conversion is performed and zero
 is returned. If the correct value is out of the range of representable values,
 INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 */

/* #include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	printf("%d\n", ft_atoi("--142"));
	printf("%d\n", ft_atoi("-+42"));
	printf("%d\n", ft_atoi("+123"));
	printf("%d\n", ft_atoi("  \t\n56"));
	printf("%d\n", ft_atoi("0"));
	printf("%d\n", ft_atoi("++-++-999"));

	printf("%d\n", atoi("--142"));
	printf("%d\n", atoi("-+42"));
	printf("%d\n", atoi("+123"));
	printf("%d\n", atoi("  \t\n56"));
	printf("%d\n", atoi("0"));
	printf("%d\n", atoi("++-++-999"));
	return (0);
} */
