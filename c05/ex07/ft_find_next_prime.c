/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juholee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:56:12 by juholee           #+#    #+#             */
/*   Updated: 2021/03/14 15:47:01 by juholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_it_prime(int nb)
{
	int i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (nb / i >= i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	int i;
	int next_prime;

	i = 2;
	next_prime = nb;
	while (is_it_prime(next_prime) == 0)
		next_prime++;
	return (next_prime);
}
