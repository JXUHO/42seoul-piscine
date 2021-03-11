/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 09:31:00 by jaemjung          #+#    #+#             */
/*   Updated: 2021/03/07 09:58:24 by hbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		get_map_size(char *input)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (input[i])
	{
		if (i % 2 == 0)
		{
			if (input[i] < '1' || input[i] > '9')
				return (NOT_OK);
			else
				cnt++;
		}
		else
		{
			if (input[i] != ' ')
				return (NOT_OK);
		}
		i++;
	}
	if (cnt % 4 != 0 || cnt > 36 || input[i - 1] < '1' || input[i - 1] > '9')
		return (NOT_OK);
	return (cnt / 4);
}

int		is_input_valid(int argc, char *input)
{
	int i;
	int size;

	if (argc != 2)
		return (0);
	size = get_map_size(input);
	if (size == NOT_OK)
		return (NOT_OK);
	i = 0;
	while (input[i])
	{
		if (i % 2 == 0)
		{
			if (input[i] > ('0' + size) || input[i] < '1')
				return (NOT_OK);
		}
		i++;
	}
	return (size);
}

int		**malloc_map(int size)
{
	int **arr;
	int i;

	if (!(arr = (int **)malloc(sizeof(int*) * (size + 2))))
		return (arr);
	i = 0;
	while (i < size + 2)
	{
		if (!(arr[i] = (int *)malloc(sizeof(int) * (size + 2))))
			return (arr);
		i++;
	}
	return (arr);
}

void	free_map(int **arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return ;
}

void	put_input(int **map, int size, char *input)
{
	int i;

	i = 0;
	while (input[i] != '\0')
	{
		if (i < size * 2)
			map[0][1 + i / 2 % size] = input[i] - '0';
		else if (i < size * 4)
			map[size + 1][1 + i / 2 % size] = input[i] - '0';
		else if (i < size * 6)
			map[1 + i / 2 % size][0] = input[i] - '0';
		else if (i < size * 8)
			map[1 + i / 2 % size][size + 1] = input[i] - '0';
		i += 2;
	}
	return ;
}
