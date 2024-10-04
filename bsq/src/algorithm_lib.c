/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_lib.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:58:36 by alneuman          #+#    #+#             */
/*   Updated: 2024/09/18 23:26:59 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm_lib.h"
#include "matrix.h"
#include "utils.h"
#include "read_map.h"

static int	min_3_plus_1(int x, int y, int z);
static char	matrix_read_out_of_bound_0(t_matrix matrix, int row, int col);

// finds the maximum value saved in a matrix and saves it's coordinates into
// *x and *y
void	matrix_find_max(t_matrix matrix, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	*x = 0;
	*y = 0;
	while (i < matrix->num_rows)
	{
		j = 0;
		while (j < matrix->num_cols)
		{
			if (matrix_read(matrix, i, j) > matrix_read(matrix, *x, *y))
			{
				*x = i;
				*y = j;
			}
			j++;
		}
		i++;
	}
}

// writes the correct number into the count_matrix
// (as the algorithm demands)
void	count_matrix_write(t_matrix count_matrix, int row, int col)
{
	matrix_write(count_matrix,
		min_3_plus_1(matrix_read_out_of_bound_0(count_matrix, row + 1, col),
			matrix_read_out_of_bound_0(count_matrix, row + 1, col + 1),
			matrix_read_out_of_bound_0(count_matrix, row, col + 1)),
		row, col);
}

// takes the min of three values and
// returns it + 1
static int	min_3_plus_1(int x, int y, int z)
{
	if (x <= y)
	{
		if (x <= z)
			return (x + 1);
		if (z <= x)
			return (z + 1);
	}
	else
	{
		if (z <= y)
			return (z + 1);
	}
	return (y + 1);
}

// returns 0 if try to read out of bound
// used by count_matrix_write
static char	matrix_read_out_of_bound_0(t_matrix matrix, int row, int col)
{
	char	c;

	c = matrix_read(matrix, row, col);
	if (c == -2)
		c = 0;
	return (c);
}

void	fill_matrix(t_matrix matrix, int fh)
{
	int	i;

	i = 0;
	while (i < matrix->num_rows)
	{
		read(fh, matrix->entries[i], matrix->num_cols);
		read(fh, matrix->entries[++i], 1);
	}
}
