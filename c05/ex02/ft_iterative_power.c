/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juholee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:38:22 by juholee           #+#    #+#             */
/*   Updated: 2021/03/14 11:44:16 by juholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int output;

	output = 1;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power >= 1)
	{
		output *= nb;
		power--;
	}
	return (output);
}
