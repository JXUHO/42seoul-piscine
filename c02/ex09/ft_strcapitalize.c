/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juholee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 22:40:53 by juholee           #+#    #+#             */
/*   Updated: 2021/02/25 22:53:19 by juholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int		lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int		number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		etc(char c)
{
	if ((lower(c) == 0) && (upper(c) == 0) && (number(c) == 0))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	if (lower(str[0]) && str[0] != '\0')
		str[0] -= 32;
	i = 1;
	while (str[i] != '\0')
	{
		if (etc(str[i - 1]))
		{
			if (lower(str[i]))
				str[i] -= 32;
		}
		if (upper(str[i - 1]) || lower(str[i - 1]) || number(str[i - 1]))
		{
			if (upper(str[i]))
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
