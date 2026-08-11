/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:24:29 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 22:31:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

/*
 1. copy up to size - 1 characters from the string src to dst, NUL-terminating
  the result if size is not 0
 2. return the total length of the string they tried to create
 3. if the return value is >= size, the output string has been truncated.
 4. it is the caller's responsibility to handle this.
 */
/* #include <stdio.h>

int	main(void)
{
	char	dst[20];

	ft_strlcpy(dst, "hello", 20);
	printf("%s\n", dst);
	return (0);
} */