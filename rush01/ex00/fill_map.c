/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbyun <hbyun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 09:52:03 by hbyun             #+#    #+#             */
/*   Updated: 2021/03/07 09:58:06 by hbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_overlap(int r, int c, int **map)
{
	int i;

	i = 1;
	while (i < r)
	{
		if (map[i][c] == map[r][c])
			return (NOT_OK);
		i++;
	}
	i = 1;
	while (i < c)
	{
		if (map[r][i] == map[r][c])
			return (NOT_OK);
		i++;
	}
	return (OK);
}

int	fill_boxes(int r, int c, int **map, int size)
{
	int i;
	int rslt;

	if (r > size)
	{
		if (is_correct(map, size))
			return (OK);
		else
			return (NOT_OK);
	}
	rslt = 0;
	i = 0;
	while (++i <= size && !rslt)
	{
		map[r][c] = i;
		if (check_overlap(r, c, map))
		{
			if (c + 1 > size)
				rslt = fill_boxes(r + 1, 1, map, size);
			else
				rslt = fill_boxes(r, c + 1, map, size);
		}
	}
	return (rslt);
}
