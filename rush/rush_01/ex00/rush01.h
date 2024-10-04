/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 09:19:42 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/10 09:31:48 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

# define GRID_SIZE 4

/*
 * The functions below can be found in "input_validation.c"
 * This function validates the input string
 * Converts it into an array of integer clues.
 * Returns a pointer to the valid array int.
 * Returns NULL if the input is invalid or malloc returns NULL.
*/
int		*valid_input(char *str);

// The "input_validation.c" ends here!!

/*
 * The functions below can be found in "grid_operations.c"
*/

//Returns a double pointer i.e the grid to be printed.
//Returns NULL if malloc returns NULL.
int		**create_grid(void);

// free_grid releases the allocated memory when all compute is done
void	free_grid(int **grid);

// solve_grid uses the concept of recursion and backtracking to fill in the grid
int		solve_grid(int **grid, int *clues, int row, int col);

// print_grid writes the solved grid to the stdout
void	print_grid(int **grid);

// The "grid_operations.c" ends here!!

/*
 * The function below can be found in The "visibility_checks.c"
 */

// is_valid Returns 1 if the in current computation is valid else 0

int		is_valid(int **grid, int *clues, int row, int col);

// The "visibility_checks.c" ends here!!

/*
 * The function below can be found in The "utils.c"
 */

// ft_putstr write the string to stdout.
void	ft_putstr(char *str);

#endif