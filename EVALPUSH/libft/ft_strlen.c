/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:24:31 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 22:31:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stddef.h>
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
 1. compute the length of the string s
 2. return the number of characters that precede the terminating NUL character
 */
/* #include <stdio.h>

int main(void)
{
    printf("%zu \n", ft_strlen("Yasafdasfasndasjdassh"));
    return (0);
}  */