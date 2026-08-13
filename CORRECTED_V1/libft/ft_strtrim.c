/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:21:27 by marvin            #+#    #+#             */
/*   Updated: 2026/05/05 18:21:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_check_set(*s1, set))
		s1++;
	size = ft_strlen(s1);
	while (size && ft_check_set(s1[size - 1], set))
		size--;
	new = (char *)malloc((size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, size + 1);
	return (new);
}

/*
 1. allocate and return a copy of 's1' with the characters specified in 'set'
  removed from the beginning and the end of the string
 2. 'set' is the set of characters to trim
 3. if the allocation fails, the function returns NULL
 */
/* #include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*result;

	result = ft_strtrim("  hello  ", " ");
	printf("%s\n", result);
	free(result);
	return (0);
}	*/