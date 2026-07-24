/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:24:41 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 22:32:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
/*
 1. convert an uppercase letter to lowercase
 2. if the argument is an uppercase letter, return its lowercase equivalent
 3. if the argument is not an uppercase letter, return it unchanged
 */
/* #include <stdio.h>
int	main(void)
{
	printf("%c \n", ft_tolower('Y'));
	return(0);
} */