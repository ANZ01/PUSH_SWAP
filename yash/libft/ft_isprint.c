/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:24:04 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 20:47:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (! ((c >= ' ' && c <= '~')))
		return (0);
	return (1);
}

/* int	main(void)
 #include <stdio.h>
{
	printf("%d\n", ft_isprint('a'));
	printf("%d\n", ft_isprint('\n'));
	printf("%d\n", ft_isprint('1'));
	printf("%d\n", ft_isprint('\0'));
	return (0);
} */