/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duim <duim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 09:19:30 by duim              #+#    #+#             */
/*   Updated: 2021/03/07 10:03:46 by duim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		is_correct_left(int **map, int size)
{
	int i;
	int j;
	int step;
	int cnt;

	i = 0;
	while (++i <= size)
	{
		j = 0;
		cnt = 0;
		step = 0;
		while (++j <= size)
		{
			if (step < map[i][j])
			{
				step = map[i][j];
				cnt++;
			}
		}
		if (map[i][0] != cnt)
			return (NOT_OK);
	}
	return (OK);
}

int		is_correct_right(int **map, int size)
{
	int i;
	int j;
	int step;
	int cnt;

	i = size + 1;
	while (--i >= 1)
	{
		j = size + 1;
		cnt = 0;
		step = 0;
		while (--j >= 1)
		{
			if (step < map[i][j])
			{
				step = map[i][j];
				cnt++;
			}
		}
		if (map[i][size + 1] != cnt)
			return (NOT_OK);
	}
	return (OK);
}

int		is_correct_up(int **map, int size)
{
	int i;
	int j;
	int step;
	int cnt;

	i = 0;
	while (++i <= size)
	{
		j = 0;
		cnt = 0;
		step = 0;
		while (++j <= size)
		{
			if (step < map[j][i])
			{
				step = map[j][i];
				cnt++;
			}
		}
		if (map[0][i] != cnt)
			return (NOT_OK);
	}
	return (OK);
}

int		is_correct_down(int **map, int size)
{
	int i;
	int j;
	int step;
	int cnt;

	i = size + 1;
	while (--i >= 1)
	{
		j = size + 1;
		cnt = 0;
		step = 0;
		while (--j >= 1)
		{
			if (step < map[j][i])
			{
				step = map[j][i];
				cnt++;
			}
		}
		if (map[size + 1][i] != cnt)
			return (NOT_OK);
	}
	return (OK);
}

int		is_correct(int **map, int size)
{
	if (!is_correct_left(map, size))
		return (NOT_OK);
	if (!is_correct_right(map, size))
		return (NOT_OK);
	if (!is_correct_up(map, size))
		return (NOT_OK);
	if (!is_correct_down(map, size))
		return (NOT_OK);
	return (OK);
}
