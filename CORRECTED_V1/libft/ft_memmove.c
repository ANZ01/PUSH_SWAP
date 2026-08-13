/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:24:14 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 22:29:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	char				j;
	unsigned char		*d;
	unsigned char		*s;

	i = 0;
	j = 1;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		j = -1;
		d += n - 1;
		s += n -1;
	}
	while (i < n)
	{
		*d = *s;
		d += j;
		s += j;
		i++;
	}
	return (dest);
}
/*
 1. copy n bytes from memory area src to memory area dest
 2. the memory areas may overlap: copying takes place as 
 though the bytes in src are first copied into a temporary 
 array that does not overlap src or dest, and the bytes 
 are then copied from the temporary array to dest
 3. return the original value of dest
 */
/*#include <stdio.h>

int	main(void)
{
	char	buf[] = "abcdefgh";

	ft_memmove(buf + 2, buf, 5);
	printf("%s\n", buf);
	return (0);
}	*/