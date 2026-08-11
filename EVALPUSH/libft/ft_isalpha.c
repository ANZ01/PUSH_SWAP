/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakumar <yakumar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:23:55 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/19 17:59:00 by yakumar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/* #include <stdio.h>

int	main(void)
{
	int i;

    i = 'a';
    while (i <= 'z')
    {
        printf("%d", ft_isalpha(i));
        i++;
    }
	printf("%d\n", ft_isalpha('H'));
	printf("%d\n", ft_isalpha('1'));
	printf("%d\n", ft_isalpha('a'));
	printf("%d\n", ft_isalpha(' '));
	return (0);
} */