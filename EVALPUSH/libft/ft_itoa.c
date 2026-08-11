/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 17:40:26 by marvin            #+#    #+#             */
/*   Updated: 2026/05/05 17:40:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_len(int n)
{
	int		len;
	long	nb;

	len = 0;
	nb = n;
	if (nb <= 0)
		len = 1;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	nb = n;
	len = ft_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
/*
1. The `ft_len` function calculates the number of characters needed to represent 
the integer `n` as a string, including space for a negative sign if necessary.
2. The `ft_itoa` function converts the integer `n` to a string.
It first calculates the length of the resulting string, allocates memory for it,
and then fills the string with the appropriate characters. 
If `n` is zero, it directly assigns '0' to the string. If `n` is negative, 
it sets the first character to '-' and converts `n` to its positive equivalent
 before filling in the digits. Finally, it returns the resulting string.
 */

/*#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*result;

	result = ft_itoa(0);
	printf("%s\n", result);
	free(result);

	result = ft_itoa(2147483647);
	printf("%s\n", result);
	free(result);

	result = ft_itoa(-2147483648);
	printf("%s\n", result);
	free(result);

	return (0);
} */