/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 09:20:01 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/08 13:03:58 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	**create_grid(void)
{
	int	i;
	int	j;
	int	**grid;

	grid = (int **)malloc((GRID_SIZE) * sizeof(int *));
	if (!grid)
		return (NULL);
	i = 0;
	while (i < GRID_SIZE)
	{
		grid[i] = (int *)malloc(GRID_SIZE * sizeof(int));
		if (!grid[i])
		{
			while (--i >= 0)
				free(grid[i]);
			free(grid);
			return (NULL);
		}
		j = 0;
		while (j < GRID_SIZE)
			grid[i][j++] = 0;
		i++;
	}
	return (grid);
}

void	free_grid(int **grid)
{
	int	i;

	i = 0;
	while (i < GRID_SIZE)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	solve_grid(int **grid, int *clues, int row, int col)
{
	int	num;

	if (row == GRID_SIZE)
		return (1);
	if (col == GRID_SIZE)
		return (solve_grid(grid, clues, row + 1, 0));
	num = 1;
	while (num <= GRID_SIZE)
	{
		grid[row][col] = num;
		if (is_valid(grid, clues, row, col))
		{
			if (solve_grid(grid, clues, row, col + 1))
				return (1);
		}
		grid[row][col] = 0;
		num++;
	}
	return (0);
}

void	print_grid(int **grid)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < GRID_SIZE)
	{
		col = 0;
		while (col < GRID_SIZE)
		{
			c = grid[col][row] + '0';
			write(1, &c, 1);
			if (col < GRID_SIZE - 1)
				write(1, " ", 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
