/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juholee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:44:53 by juholee           #+#    #+#             */
/*   Updated: 2021/03/11 16:58:03 by juholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		exception(int len, char *base)
{
	int i;
	int j;

	i = 0;
	if (len == 1 || len == 0)
		return (1);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		is_str_in_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (1);
		i++;
	}
	return (0);
}

int		str_to_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

int		atoi_base(char *str, char *base, int baselen)
{
	int i;
	int temp;
	int output;

	i = 0;
	temp = 1;
	output = 0;
	while (str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
	|| str[i] == '\t' || str[i] == '\v' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			temp *= -1;
		i++;
	}
	while (is_str_in_base(str[i], base) && str[i] != '\0')
	{
		output *= baselen;
		output += str_to_base(str[i], base);
		i++;
	}
	return (output * temp);
}

int		ft_atoi_base(char *str, char *base)
{
	int len;

	len = 0;
	while (base[len] != '\0')
		len++;
	if (exception(len, base))
		return (0);
	return (atoi_base(str, base, len));
}
