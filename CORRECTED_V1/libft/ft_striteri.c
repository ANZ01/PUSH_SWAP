/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 17:37:17 by marvin            #+#    #+#             */
/*   Updated: 2026/05/06 17:37:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
 1. apply the function 'f' to each character of the string passed as argument,
  and passing its index as first argument
 2. each character is passed by address to 'f' to be modified if necessary
 */
/* #include <stdio.h>
void	to_upper_even(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c -= 32;
}

int	main(void)
{
	char	str[] = "hello world";

	// Normal case
	printf("Before:    %s\n", str);
	ft_striteri(str, to_upper_even);
	printf("After:     %s\n", str);

	// NULL string
	ft_striteri(NULL, to_upper_even);
	printf("NULL str:  OK (no crash)\n");

	// NULL function
	char	str2[] = "test";
	ft_striteri(str2, NULL);
	printf("NULL func: OK (no crash)\n");

	return (0);
} */
