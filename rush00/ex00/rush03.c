/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongjule <yongjule@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 11:05:13 by yongjule          #+#    #+#             */
/*   Updated: 2021/02/21 12:03:36 by yongjule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);


void	ft_print_lines(int index, char start, char mid, char end)
{
	int		i;

	i = 0;
	ft_putchar(start);
	while (i < index - 2)
	{
		ft_putchar(mid);
		i++;
	}
	if (index != 1)
		ft_putchar(end);
	ft_putchar('\n');
}

void	rush(int y, int x)
{
	int		i;

	i = 0;
	if (y <= 0 || x <= 0)
		return ;
	ft_print_lines(y, 'A', 'B', 'C');
	while (i < x - 2)
	{
		ft_print_lines(y, 'B', ' ', 'B');
		i++;
	}
	if (x != 1)
		ft_print_lines(y, 'A', 'B', 'C');
}
