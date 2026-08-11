/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:24:16 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 22:29:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}

/*
 1. fill the first n bytes of the memory area pointed to by s 
 with the constant byte c
 2. return a pointer to the memory area s
 */
/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	buf_ft[10] = "hello";
	char	buf_std[10] = "hello";

	ft_memset(buf_ft, 'x', 10);
	memset(buf_std, 'x', 10);
	printf("ft_memset: %s\n", buf_ft);
	printf("memset:    %s\n", buf_std);
	return (0);
} */