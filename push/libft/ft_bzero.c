/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:23:43 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/13 13:09:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
/*
*s is a void pointer to the memory area to be filled with zeros.
*n is the number of bytes to be set to zero.
 1. write n zeroed bytes to the string s
 2. if n is zero, bzero does nothing
 */
/*#include <stdio.h>
int	main(void)
{
	char	buf[5];
	int		i;

	buf[0] = 1;
	buf[1] = 2;
	buf[2] = 3;
	buf[3] = 4;
	buf[4] = 5;
	ft_bzero(buf, 5);
	i = 0;
	while (i < 5)
	{
		printf("%d ", buf[i]);
		i++;
	}
	printf("\n");
	return (0);
}	*/