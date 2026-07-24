/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:24:06 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/08 19:36:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (((unsigned char *)s) + i);
		i++;
	}
	return (NULL);
}
/*
 1. scan the initial n bytes of the memory area pointed to by s 
 for the first instance of c
 2. both c and the bytes of the memory area pointed to by s 
 are interpreted as unsigned char
 3. return a pointer to the matching byte or NULL if 
 the character does not occur in the given memory area
 */
/* #include <stdio.h>
#include <string.h>

int main(void)
{
    char *str = "hello world";

    printf("%s\n", (char *)ft_memchr(str, 'o', 11));
    printf("%s\n", (char *)ft_memchr(str, 'z', 11)); 

    return (0);
} */