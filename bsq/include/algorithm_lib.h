/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:49:37 by alneuman          #+#    #+#             */
/*   Updated: 2024/09/18 23:25:59 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_LIB_H
# define ALGORITHM_LIB_H

# include "matrix.h"
# include "read_map.h"

// writes the correct number into the count_matrix
// (as the algorithm demands)
void	count_matrix_write(t_matrix count_matrix, int row, int col);

// finds the maximum value saved in a matrix and saves it's coordinates into
// *x and *y
void	matrix_find_max(t_matrix matrix, int *x, int *y);
void	fill_matrix(t_matrix matrix, int fh);

#endif //ALGORITHM_LIB_H
