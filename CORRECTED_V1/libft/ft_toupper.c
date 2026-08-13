/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:24:44 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 22:32:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
/*
 1. convert a lowercase letter to uppercase
 2. if the argument is a lowercase letter, return its uppercase equivalent
 3. if the argument is not a lowercase letter, return it unchanged
 */
/* #include <stdio.h>
int	main(void)
{
	printf("%c \n", ft_toupper('Y'));
	return(0);
} */