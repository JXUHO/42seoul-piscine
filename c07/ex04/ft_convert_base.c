/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juholee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 19:54:25 by juholee           #+#    #+#             */
/*   Updated: 2021/03/17 16:41:14 by juholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			count_baselen(char *base);
int			get_num(char c, char *base);
int			ft_atoi_base(char *str, char *base);
char		*int_to_str(long long input, char *base);
int			is_base_null(char *base);

char		*get_str_reverse(char *str)
{
	int		i;
	int		j;
	char	*temp;

	if (!(temp = (char*)malloc(33)))
		return (0);
	j = 0;
	while (j++ < 33)
		temp[j] = '\0';
	i = 0;
	while (str[i])
		i++;
	j = 0;
	while (--i >= 0)
	{
		temp[j] = str[i];
		j++;
	}
	return (temp);
}

int			base_check(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i])
	{
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 0 || i == 1)
		return (0);
	return (1);
}

char		get_first(char *nbr)
{
	int		i;

	i = 0;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
		i++;
	return (nbr[i]);
}

int			is_nbr_zero(char *nbr, char *base_from)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
		i++;
	while (base_from[j])
	{
		if (nbr[i + 1] == base_from[j])
			return (0);
		j++;
	}
	return (1);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		step1;
	char	*step2;
	char	*output;
	char	*zero_output;
	char	temp;

	if (!(base_check(base_from)) || !(base_check(base_to)))
		return (0);
	if (!(zero_output = (char*)malloc(2)))
		return (0);
	if (get_first(nbr) == get_first(base_from) && is_nbr_zero(nbr, base_from))
	{
		temp = get_first(base_to);
		zero_output[0] = temp;
		zero_output[1] = '\0';
		return (zero_output);
	}
	step1 = ft_atoi_base(nbr, base_from);
	if (!(step2 = int_to_str(step1, base_to)))
		return (0);
	output = get_str_reverse(step2);
	return (output);
}
