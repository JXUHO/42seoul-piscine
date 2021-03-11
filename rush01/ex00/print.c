/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juholee <juholee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 09:27:22 by juholee           #+#    #+#             */
/*   Updated: 2021/03/07 09:58:34 by hbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		print_error(int err)
{
	write(1, "Error\n", 6);
	return (err);
}

void	put_number(int n)
{
	char c;

	c = n + '0';
	write(1, &c, 1);
}

void	print_ans(int **map, int size)
{
	int i;
	int j;

	i = 1;
	while (i <= size)
	{
		j = 1;
		while (j <= size)
		{
			put_number(map[i][j]);
			if (j != size)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
