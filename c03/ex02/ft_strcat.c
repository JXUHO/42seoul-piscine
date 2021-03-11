/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juholee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 14:40:10 by juholee           #+#    #+#             */
/*   Updated: 2021/03/07 14:42:13 by juholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int dest_null;

	i = 0;
	dest_null = 0;
	while (dest[i] != '\0')
		i++;
	dest_null = i;
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_null] = src[i];
		i++;
		dest_null++;
	}
	dest[dest_null] = '\0';
	return (dest);
}
