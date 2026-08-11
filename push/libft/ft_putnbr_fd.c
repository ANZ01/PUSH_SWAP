/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 02:25:49 by yakumar           #+#    #+#             */
/*   Updated: 2026/05/06 19:40:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd((nb % 10) + '0', fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
}
/* #include <unistd.h>
int	main(void)
{
	ft_putnbr_fd(42, 1);
	write(1, "\n", 1);

	ft_putnbr_fd(0, 1);
	write(1, "\n", 1);

	ft_putnbr_fd(-42, 1);
	write(1, "\n", 1);

	ft_putnbr_fd(2147483647, 1);
	write(1, "\n", 1);

	ft_putnbr_fd(-2147483648, 1);
	write(1, "\n", 1);

	return (0);
} */