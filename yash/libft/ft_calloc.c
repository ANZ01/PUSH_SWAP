/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:23:46 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 22:36:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*temp;
	size_t	i;

	i = 0;
	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	while (i < count * size)
		temp[i++] = 0;
	return (temp);
}
/*
 1. allocate memory for an array of count elements of size bytes each
 2. the allocated memory is filled with bytes of value zero
 3. if count or size is 0, then calloc returns either NULL, or a unique
 pointer value that can later be successfully passed to free()
 4. if the allocation fails, the function returns NULL
 */
/* #include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int	*arr;
	int	i;

	arr = ft_calloc(5, sizeof(int));
	i = 0;
	while (i < 5)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
	free(arr);
	return (0);
}	*/