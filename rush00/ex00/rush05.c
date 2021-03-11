/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush05.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juholee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 14:35:25 by juholee           #+#    #+#             */
/*   Updated: 2021/02/23 14:45:42 by juholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_row(int x, char end1, char end2, char btw)
{
	int index;

	ft_putchar(end1);
	index = 1;
	while (index < x - 1)
	{
		ft_putchar(btw);
		index++;
	}
	if (x != 1)
		ft_putchar(end2);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int index;

	if (x <= 0 || y <= 0)
		return ;
	ft_print_row(x, 'A', 'C', 'B');
	index = 1;
	while (index < y - 1)
	{
		ft_print_row(x, 'B', 'B', ' ');
		index++;
	}
	if (y != 1)
		ft_print_row(x, 'C', 'A', 'B');
}
