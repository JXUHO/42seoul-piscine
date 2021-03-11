/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juholee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:28:50 by juholee           #+#    #+#             */
/*   Updated: 2021/02/25 11:42:48 by juholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (0 <= nb && nb < 10)
		put_char(nb + '0');
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		put_char((nb % 10) + '0');
	}
	else if (nb < 0)
	{
		nb = nb * -1;
		put_char('-');
		ft_putnbr(nb);
	}
}
