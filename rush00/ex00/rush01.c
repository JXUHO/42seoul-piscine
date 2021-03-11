/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhekim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 09:54:21 by minhekim          #+#    #+#             */
/*   Updated: 2021/02/21 10:32:00 by minhekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_row(int x, char end1, char between, char end2)
{
	int		index;

	ft_putchar(end1);
	index = 1;
	while (index < x - 1)
	{
		ft_putchar(between);
		index++;
	}
	if (x != 1)
		ft_putchar(end2);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int		index;

	if (x <= 0 || y <= 0)
		return ;
	ft_print_row(x, '/', '*', '\\');
	index = 1;
	while (index < y - 1)
	{
		ft_print_row(x, '*', ' ', '*');
		index++;
	}
	if (y != 1)
		ft_print_row(x, '\\', '*', '/');
}
