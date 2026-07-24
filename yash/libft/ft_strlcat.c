/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:24:26 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 22:31:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (size <= dst_len)
		return (size + src_len);
	while (src[i] && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*
 1. appends string src to the end of dst
 2. it will append at most size - strlen(dst) - 1 characters
 3. it will then NUL-terminate, unless size is 0 or the original dst string
 was longer than size (in practice this should not happen as it means that
 either size is incorrect or that dst is not a proper string)
 4. return the total length of the string they tried to create
 5. if the return value is >= size, the output string has been truncated.
 6. it is the caller's responsibility to handle this.
 */
/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dst[20] = "hello ";
	char	src[] = "world";

	ft_strlcat(dst, src, 20);
	printf("%s\n", dst);
	return (0);
} */