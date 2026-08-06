/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:24:01 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 20:47:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/* #include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_isdigit('H'));
	printf("%d\n", ft_isdigit('1'));
	printf("%d\n", ft_isdigit('a'));
	printf("%d\n", ft_isdigit('2'));
	return (0);
} */