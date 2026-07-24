/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:24:34 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 22:32:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char)s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

/*
 1. compare at most n bytes of s1 and s2
 2. return an integer less than, equal to, or greater than zero if s1 (or the
  first n bytes thereof) is found, respectively, to be less than, to match, or
  be greater than s2 (or the first n bytes thereof)
 3. the comparison is done using unsigned characters,
  so that `\200' is greater than `\0'
 */
/* #include <stdio.h>
#include <string.h>
#include <stddef.h>
int main(void)
{
    printf("  ft_strncmp: %d\n", ft_strncmp("hello", "hello", 5));
    printf("  strncmp:    %d\n", strncmp("hello", "hello", 5));
    
    return (0);
} */