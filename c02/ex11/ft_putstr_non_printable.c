/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juholee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 15:42:28 by juholee           #+#    #+#             */
/*   Updated: 2021/03/07 19:08:52 by juholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_it_nonp(char c)
{
	if (c >= 32 && c <= 127)
		return (0);
	else
		return (1);
}

void	trans_hexa(unsigned char c)
{
	char *hexa;

	hexa = "0123456789abcdef";
	write(1, &hexa[c / 16], 1);
	write(1, &hexa[c % 16], 1);
}

void	print_hexa(unsigned char c)
{
	write(1, "\\", 1);
	trans_hexa(c);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_it_nonp(str[i]))
			print_hexa(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
