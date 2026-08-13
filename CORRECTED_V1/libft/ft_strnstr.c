/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:24:36 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/09 14:30:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (needle[0] == 0)
		return ((char *) haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] && i + j < len)
		{
			j++;
			if (needle[j] == 0)
				return ((char *) haystack + i);
		}
		i++;
		j = 0;
	}
	return (0);
}

/*
 1. locate the first occurrence of the null-terminated string needle in the
  string haystack, where not more than len characters are searched
 2. characters that appear after a `\0' character are not searched
 3. if needle is an empty string, haystack is returned; if needle occurs nowhere
  in haystack, NULL is returned; otherwise a pointer to the first character of
  the first occurrence of needle is returned
 */

/*#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strnstr("hello world", "world", 11));
	printf("%s\n", ft_strnstr("hello world", "aworld", 16));
	return (0);
}*/