/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 09:20:51 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/08 13:34:07 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	count_visible_boxes(int *line, int size)
{
	int	max_height;
	int	count;
	int	i;

	max_height = 0;
	count = 0;
	i = 0;
	while (i < size)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			count++;
		}
		i++;
	}
	return (count);
}

static int	count_visible_boxes_reverse(int *line, int size)
{
	int	max_height;
	int	count;
	int	i;

	max_height = 0;
	count = 0;
	i = size - 1;
	while (i >= 0)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			count++;
		}
		i--;
	}
	return (count);
}

static int	check_row(int **grid, int *clues, int row, int col)
{
	int	line[GRID_SIZE];
	int	i;

	i = 0;
	while (i < GRID_SIZE)
	{
		line[i] = grid[row][i];
		i++;
	}
	if (col == GRID_SIZE - 1 
		&& count_visible_boxes(line, GRID_SIZE) != clues[row])
		return (0);
	if (col == GRID_SIZE - 1 && count_visible_boxes_reverse(line, GRID_SIZE)
		!= clues[GRID_SIZE + row])
		return (0);
	return (1);
}

static int	check_col(int **grid, int *clues, int row, int col)
{
	int	line[GRID_SIZE];
	int	i;

	i = 0;
	while (i < GRID_SIZE)
	{
		line[i] = grid[i][col];
		i++;
	}
	if (row == GRID_SIZE - 1 && count_visible_boxes(line, GRID_SIZE)
		!= clues[2 * GRID_SIZE + col])
		return (0);
	if (row == GRID_SIZE - 1 && count_visible_boxes_reverse(line, GRID_SIZE)
		!= clues[3 * GRID_SIZE + col])
		return (0);
	return (1);
}

int	is_valid(int **grid, int *clues, int row, int col)
{
	int	i;

	i = 0;
	while (i < GRID_SIZE)
	{
		if (i != col && grid[row][i] == grid[row][col])
			return (0);
		if (i != row && grid[i][col] == grid[row][col])
			return (0);
		i++;
	}
	if (!check_row(grid, clues, row, col) || !check_col(grid, clues, row, col))
		return (0);
	return (1);
}
