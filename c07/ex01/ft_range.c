/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juholee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:39:22 by juholee           #+#    #+#             */
/*   Updated: 2021/03/14 16:20:34 by juholee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int i;
	int mn;
	int *temp;

	i = 0;
	mn = min;
	if (max - min <= 0)
		return (0);
	temp = (int*)malloc(sizeof(int) * (max - min));
	while (i < (max - min))
	{
		temp[i] = mn;
		i++;
		mn++;
	}
	return (temp);
}
