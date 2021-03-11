/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjung <jaemjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 09:41:09 by jaemjung          #+#    #+#             */
/*   Updated: 2021/03/07 09:58:43 by hbyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# include <unistd.h>
# include <stdlib.h>

# define INPUT_FORMAT_ERROR -1
# define MALLOC_ERROR -2
# define NO_SOLUTION_ERROR -3
# define OK 1
# define NOT_OK 0

int		get_map_size(char *input);
int		is_input_valid(int argc, char *input);
int		**malloc_map(int size);
void	free_map(int **arr, int size);
void	put_input(int **map, int size, char *input);
int		is_correct_left(int **map, int size);
int		is_correct_right(int **map, int size);
int		is_correct_up(int **map, int size);
int		is_correct_down(int **map, int size);
int		is_correct(int **map, int size);
int		check_overlap(int r, int c, int **map);
int		fill_boxes(int r, int c, int **map, int size);
int		print_error(int err);
void	put_number(int n);
void	print_ans(int **map, int size);

#endif
