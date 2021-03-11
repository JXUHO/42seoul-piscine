/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juholee <juholee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 09:23:03 by juholee           #+#    #+#             */
/*   Updated: 2021/03/07 09:58:14 by hbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		main(int argc, char *argv[])
{
	int size;
	int **map;

	size = is_input_valid(argc, argv[1]);
	if (size == NOT_OK)
		return (print_error(INPUT_FORMAT_ERROR));
	map = malloc_map(size);
	if (!map)
		return (print_error(MALLOC_ERROR));
	put_input(map, size, argv[1]);
	if (!fill_boxes(1, 1, map, size))
	{
		free_map(map, size);
		return (print_error(NO_SOLUTION_ERROR));
	}
	else
	{
		print_ans(map, size);
		free_map(map, size);
	}
	return (0);
}
