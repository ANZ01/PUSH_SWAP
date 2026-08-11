/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:24:19 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 22:31:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}
/*
 1. locate the first occurrence of c (converted to a char)
  in the string pointed to by s
 2. the terminating null character is considered to be part
  of the string; therefore if c is `\0', the functions locate
   the terminating `\0'
 3. return a pointer to the located character,
  or NULL if the character does not appear in the string
 */
/* #include <stdio.h>

int	main(void)
{
	char	*result;

	result = ft_strchr("hello world", 'w');
	printf("%s\n", result ? result : "NULL");
	return (0);
}*/