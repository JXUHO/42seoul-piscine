/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhekim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 09:54:21 by minhekim          #+#    #+#             */
/*   Updated: 2021/02/21 10:32:11 by minhekim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_row(int x, char ends, char between)
{
	int		index;

	ft_putchar(ends);
	index = 1;
	while (index < x - 1)
	{
		ft_putchar(between);
		index++;
	}
	if (x != 1)
		ft_putchar(ends);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int		index;

	if (x <= 0 || y <= 0)
		return ;
	ft_print_row(x, 'A', 'B');
	index = 1;
	while (index < y - 1)
	{
		ft_print_row(x, 'B', ' ');
		index++;
	}
	if (y != 1)
		ft_print_row(x, 'C', 'B');
}
