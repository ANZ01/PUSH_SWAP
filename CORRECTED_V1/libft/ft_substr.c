/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 01:32:59 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 22:32:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

/*
 1. allocate and return a substring from the string 's'
 2. the substring begins at index 'start' and is of maximum size 'len'
 3. if 'start' is greater than the length of 's', the function returns an empty
  string
 4. if the allocation fails, the function returns NULL
 */
/* #include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*result;

	result = ft_substr("hello world", 6, 5);
	printf("%s\n", result);
	free(result);
	return (0);
} */