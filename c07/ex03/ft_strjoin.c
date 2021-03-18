/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juholee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 18:41:34 by juholee           #+#    #+#             */
/*   Updated: 2021/03/15 19:44:26 by juholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*ft_strcat(char *dest, char *src)
{
	int		i;
	int		dest_null;

	i = 0;
	while (dest[i])
		i++;
	dest_null = i;
	i = 0;
	while (src[i])
	{
		dest[dest_null] = src[i];
		dest_null++;
		i++;
	}
	dest[dest_null] = '\0';
	return (dest);
}

int			get_str_len(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		str_len;
	int		sep_len;

	i = -1;
	str_len = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			j++;
		str_len += j;
	}
	sep_len = ft_strlen(sep) * (size - 1);
	return (sep_len + str_len + 1);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*output;

	if (size == 0)
	{
		if (!(output = malloc(1)))
			output = 0;
		return (output);
	}
	i = 0;
	if (!(output = (char*)malloc(get_str_len(size, strs, sep))))
		return (0);
	output[0] = '\0';
	while (i < size - 1)
	{
		output = ft_strcat(output, strs[i]);
		output = ft_strcat(output, sep);
		i++;
	}
	output = ft_strcat(output, strs[i]);
	return (output);
}
