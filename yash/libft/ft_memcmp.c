/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:24:09 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 22:29:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((*str1 == *str2) && n -1 > 0)
	{
		++str1;
		++str2;
		--n;
	}
	return ((int)(*str1 - *str2));
}
/*
 1. compare the first n bytes of memory area s1 and memory area s2
 2. return an integer less than, equal to, or greater than zero 
 if the first n bytes of s1 is found, respectively, to be less than,
  to match, or be greater than the first n bytes of s2
 3. the comparison is done using unsigned characters,
  so that `\200' is greater than `\0'
 */

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char a[] = "Hello world2";
	char b[] = "Hello world2";
	
	printf("My function   = %d \n", ft_memcmp(a, b, sizeof(b)));
	printf("Real function = %d \n", memcmp(a, b, sizeof(b)));
} */