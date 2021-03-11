/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juholee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:38:04 by juholee           #+#    #+#             */
/*   Updated: 2021/03/11 17:10:55 by juholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		exception(int len, char *base)
{
	int i;
	int j;

	i = 0;
	if (len == 0 || len == 1)
		return (1);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	to_base(int nbr, int len, char *base)
{
	int i;

	if (nbr == 0)
		return ;
	to_base(nbr / len, len, base);
	i = nbr % len;
	if (i < 0)
		i *= (-1);
	write(1, &base[i], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int len;

	len = 0;
	while (base[len] != '\0')
		len++;
	if (nbr == 0)
		write(1, "0", 1);
	if (exception(len, base) || nbr == '\0')
		return ;
	if (nbr < 0)
		write(1, "-", 1);
	to_base(nbr, len, base);
}
