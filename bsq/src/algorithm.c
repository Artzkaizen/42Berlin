/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:35:45 by alneuman          #+#    #+#             */
/*   Updated: 2024/09/18 23:26:49 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm_lib.h"
#include "matrix.h"
#include "read_map.h"

static int	solve(t_matrix matrix, char obstacle, char full);
static void	matrix_fill_square(t_matrix matrix,
				t_matrix count_matrix, char full);
static void	count_matrix_write_numbers(t_matrix count_matrix,
				t_matrix map_matrix, char obstacle);

// return values
// success			-> 0
// out of memory	-> -1
// map error		-> -2

int	finish_algo(char *map, t_matrix matrix, t_map_params *params)
{
	int	fh_open;

	fh_open = open(map, O_RDONLY);
	get_line_length(fh_open);
	fill_matrix(matrix, fh_open);
	if (solve(matrix, params->obstacle, params->full) == -1)
	{
		free(params);
		matrix_destroy(matrix);
		close(fh_open);
		return (-1);
	}
	matrix_print(matrix);
	free(params);
	matrix_destroy(matrix);
	close(fh_open);
	return (0);
}

int	run_alg(char *map)
{
	t_map_params	*params;
	t_matrix		matrix;

	params = malloc(sizeof(*params));
	if (!params)
		return (-1);
	if (!is_valid_map(map, params))
	{
		free(params);
		return (-2);
	}
	matrix = matrix_create(params->row_count, params->line_count);
	if (!matrix)
	{
		free(params);
		return (-1);
	}
	return (finish_algo(map, matrix, params));
}

// return values
// success			-> 0
// out of memory	-> -1
// other error		-> -2
int	solve(t_matrix matrix, char obstacle, char full)
{
	t_matrix	count_matrix;

	count_matrix = matrix_create(matrix->num_rows, matrix->num_cols);
	if (!count_matrix)
		return (-1);
	count_matrix_write_numbers(count_matrix, matrix, obstacle);
	matrix_fill_square(matrix, count_matrix, full);
	matrix_destroy(count_matrix);
	return (0);
}

static void	count_matrix_write_numbers(t_matrix count_matrix,
				t_matrix map_matrix, char obstacle)
{
	int			i;
	int			j;

	i = map_matrix->num_rows - 1;
	while (i >= 0)
	{
		j = map_matrix->num_cols - 1;
		while (j >= 0)
		{
			if (obstacle == matrix_read(map_matrix, i, j))
				matrix_write(count_matrix, 0, i, j);
			else
				count_matrix_write(count_matrix, i, j);
			j--;
		}
		i--;
	}
}

static void	matrix_fill_square(t_matrix matrix,
				t_matrix count_matrix, char full)
{
	int	x;
	int	y;
	int	max;
	int	i;
	int	j;

	matrix_find_max(count_matrix, &x, &y);
	max = matrix_read(count_matrix, x, y);
	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			matrix_write(matrix, full, x + i, y + j);
			j++;
		}
		i++;
	}
}
//
//#ifdef TEST
//# include "utils.h"
//static int	matrix_print_test(t_matrix matrix)
//{
//	int	i;
//	int	j;
//	int	c;
//
//	if (!matrix)
//		return (-1);
//	i = 0;
//	while (i < matrix->num_rows)
//	{
//		j = 0;
//		while (j < matrix->num_cols)
//		{
//			c = matrix_read(matrix, i, j);
//			if (c == -1 || c == -2)
//				return (-1);
//			ft_putchar(c + '0');
//			j++;
//		}
//		ft_putchar('\n');
//		i++;
//	}
//	return (0);
//}
//#endif //TEST
