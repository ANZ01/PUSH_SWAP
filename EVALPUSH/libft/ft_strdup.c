/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:22:09 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 22:31:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		size;
	char	*strcp;

	size = 0;
	while (src[size])
	{
		size++;
	}
	strcp = malloc(sizeof(char) * (size + 1));
	if (!strcp)
		return (NULL);
	size = 0;
	while (src[size])
	{
		strcp[size] = src[size];
		size++;
	}
	strcp[size] = '\0';
	return (strcp);
}
/*
 1. duplicate the string 'src' by allocating sufficient memory for a copy of
  the string, does the copy, and returns a pointer to it
 2. the pointer may subsequently be used as an argument to the function free(3)
 3. if insufficient memory is available, NULL is returned
 */
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	char	*ft;
	char	*std;

	ft = ft_strdup("hello");
	std = strdup("hello");
	printf("%s\n", strcmp(ft, std) == 0 ? "MATCH" : "DIFFER");
	free(ft);
	free(std);
	return (0);
} */