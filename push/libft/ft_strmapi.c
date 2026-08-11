/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 06:24:01 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 22:32:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new;

	if (s == NULL || f == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}

/*
 1. apply the function 'f' to each character of the string passed as argument
  to create a new string (with malloc(3)) resulting from successive applications
  of 'f'
 2. 'f' is applied to each character of 's' to create a new string 
 (with malloc(3)) resulting from successive applications of 'f'
 */
/* #include <stdio.h>
#include <stdlib.h>

static char	to_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	char	*result;

	result = ft_strmapi("hello", to_upper);
	printf("%s\n", result);
	free(result);
	return (0);
} */