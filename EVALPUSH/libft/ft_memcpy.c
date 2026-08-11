/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:22:04 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 22:46:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (!dst && !src)
		return (NULL);
	while (len > 0)
	{
		*d = *s;
		d++;
		s++;
		len--;
	}
	return (dst);
}

/*
 1. copy n bytes from memory area src to memory area dst
 2. the memory areas must not overlap
 3. return the original value of dst
 */
/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char	src[] = "hello";
	char	dst[50] = "world";
	printf("My function    = %s \n",(char *) ft_memcpy(dst, src, 15));
	printf("Real function  = %s \n",(char *) memcpy(dst, src, 15));
	
	return (0);
	
} */