/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:23:58 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 20:47:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* #include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isascii('H'));
	printf("%d\n", ft_isascii('1'));
	printf("%d\n", ft_isascii('a'));
	printf("%d\n", ft_isascii('-1'));
	return (0);
} */