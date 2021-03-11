/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juholee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 22:14:42 by juholee           #+#    #+#             */
/*   Updated: 2021/03/11 16:13:57 by juholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_it_space(char c)
{
	if (c == '\f' || c == '\n'
			|| c == '\r' || c == '\t'
			|| c == '\v' || c == ' ')
		return (1);
	else
		return (0);
}

int		is_it_plus_minus(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}

int		is_it_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		ft_atoi(char *str)
{
	int i;
	int output;
	int sign;

	i = 0;
	output = 0;
	sign = 1;
	while (is_it_space(str[i]))
		i++;
	while (is_it_plus_minus(str[i]))
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (is_it_number(str[i]) && str[i] != '\0')
	{
		output *= 10;
		output += str[i] - '0';
		i++;
	}
	return (output * sign);
}
