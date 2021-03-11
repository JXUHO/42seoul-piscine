/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juholee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 22:30:27 by juholee           #+#    #+#             */
/*   Updated: 2021/02/25 11:36:29 by juholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	put_num(int a, int b)
{
	put_char((a / 10) + '0');
	put_char((a % 10) + '0');
	put_char(' ');
	put_char((b / 10) + '0');
	put_char((b % 10) + '0');
	if (a != 98)
	{
		put_char(',');
		put_char(' ');
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 1;
	while (a < 99)
	{
		while (b < 100)
		{
			put_num(a, b);
			b++;
		}
		a++;
		b = a + 1;
	}
}
