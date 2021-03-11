/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juholee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 16:45:39 by juholee           #+#    #+#             */
/*   Updated: 2021/03/08 21:14:05 by juholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int destlen;
	unsigned int srclen;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	i = 0;
	j = destlen;
	if (size == 0)
		return (srclen);
	while (src[i] != '\0' && (destlen + i) < (size - 1))
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	if (size <= destlen)
		return (srclen + size);
	else
		return (srclen + destlen);
}
