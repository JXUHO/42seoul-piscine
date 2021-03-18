/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juholee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:59:42 by juholee           #+#    #+#             */
/*   Updated: 2021/03/18 09:27:56 by juholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				g_flag;

int				count_baselen(char *base)
{
	int			i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int				get_num(char c, char *base)
{
	int			i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int				space_plus_minus(char *nbr)
{
	int			i;

	i = 0;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	return (i);
}

int				ft_atoi_base(char *nbr, char *base)
{
	int			i;
	int			temp;
	int			baselen;
	long long	output;

	output = 0;
	temp = 1;
	baselen = count_baselen(base);
	i = space_plus_minus(nbr);
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			temp *= (-1);
		i++;
	}
	while (nbr[i])
	{
		if (get_num(nbr[i], base) == -1)
			break ;
		output = output * baselen + get_num(nbr[i], base);
		i++;
	}
	return (output * temp);
}

char			*int_to_str(long long input, char *base)
{
	int			baselen;
	char		*output;
	int			i;

	if (!(output = (char*)malloc(33)))
		return (0);
	baselen = count_baselen(base);
	g_flag = 0;
	if (((i = 0) || 1) && input < 0)
	{
		input *= (-1);
		g_flag = 1;
	}
	while (input > 0)
	{
		output[i++] = base[input % baselen];
		input /= baselen;
	}
	if (((output[i] = '\0') || 1) && g_flag)
	{
		output[i] = '-';
		output[i + 1] = '\0';
	}
	return (output);
}
