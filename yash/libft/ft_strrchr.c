/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:24:39 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 22:32:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}
/*
 1. locate the last occurrence of c (converted to a char) in the string pointed
  to by s
 2. the terminating null character is considered to be part of the string; 
 therefore if c is `\0', the functions locate the terminating `\0'
 3. return a pointer to the located character, or NULL if the character does not
  occur in the string
 */
/*#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strrchr("hello world", 'l'));
	return (0);
}	*/