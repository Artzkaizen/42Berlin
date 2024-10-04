/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:23:16 by alneuman          #+#    #+#             */
/*   Updated: 2024/09/18 19:12:03 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

typedef struct s_matrix
{
	int		num_rows;
	int		num_cols;
	char	**entries;
}	*t_matrix;

t_matrix	matrix_create(int num_rows, int num_cols);

// return values
// success			-> 0
// matrix == NULL	-> -1
int			matrix_destroy(t_matrix matrix);

// return values
// success			-> value at position
// matrix == NULL	-> -1
// out of bound		-> -2
char		matrix_read(t_matrix matrix, int row, int col);

// return values
// success			-> 0
// matrix == NULL	-> -1
// out of bound		-> -2
int			matrix_write(t_matrix matrix, char c, int row, int col);

// return values
// success		-> 0
// read error	-> -1
int			matrix_print(t_matrix matrix);

#endif //MATRIX_H
