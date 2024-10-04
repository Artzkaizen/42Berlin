/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_methods.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alneuman <alneuman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:48:46 by alneuman          #+#    #+#             */
/*   Updated: 2024/09/17 14:28:22 by alneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include "utils.h"
#include <unistd.h>

char	matrix_read(t_matrix matrix, int row, int col)
{
	if (!matrix)
		return (-1);
	if (row >= matrix->num_rows || col >= matrix->num_cols)
		return (-2);
	return (matrix->entries[row][col]);
}

int	matrix_write(t_matrix matrix, char c, int row, int col)
{
	if (!matrix)
		return (-1);
	if (row >= matrix->num_rows || col >= matrix->num_cols)
		return (-2);
	matrix->entries[row][col] = c;
	return (0);
}

int	matrix_print(t_matrix matrix)
{
	int	i;
	int	j;
	int	c;

	if (!matrix)
		return (-1);
	i = 0;
	while (i < matrix->num_rows)
	{
		j = 0;
		while (j < matrix->num_cols)
		{
			c = matrix_read(matrix, i, j);
			if (c == -1 || c == -2)
				return (-1);
			ft_putchar(c);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}
