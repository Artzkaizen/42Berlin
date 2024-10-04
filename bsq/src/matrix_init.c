/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alneuman <alneuman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:25:21 by alneuman          #+#    #+#             */
/*   Updated: 2024/09/17 14:29:13 by alneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"
#include <stdlib.h>

static char	**create_entries(int num_rows, int num_cols);

// return values
// success			-> 0
// invalid entries	-> -1
static int	entries_destroy(char **entries, int rows);

t_matrix	matrix_create(int num_rows, int num_cols)
{
	t_matrix	new_matrix;

	new_matrix = malloc(sizeof(*new_matrix));
	if (!new_matrix)
		return (NULL);
	new_matrix->entries = create_entries(num_rows, num_cols);
	if (!new_matrix->entries)
		return (NULL);
	new_matrix->num_rows = num_rows;
	new_matrix->num_cols = num_cols;
	return (new_matrix);
}

// return values
// success			-> 0
// invalid matrix	-> -1
int	matrix_destroy(t_matrix matrix)
{
	if (!matrix)
		return (-1);
	entries_destroy(matrix->entries, matrix->num_rows);
	free(matrix);
	return (0);
}

static char	**create_entries(int num_rows, int num_cols)
{
	char	**new_enries;
	int		i;

	new_enries = malloc(sizeof(*new_enries) * num_rows);
	if (!new_enries)
		return (NULL);
	i = 0;
	while (i < num_rows)
	{
		new_enries[i] = malloc(sizeof(*new_enries[i]) * num_cols);
		if (!new_enries[i])
		{
			while (--i >= 0)
				free(new_enries[i]);
			free(new_enries);
			return (NULL);
		}
		i++;
	}
	return (new_enries);
}

static int	entries_destroy(char **entries, int rows)
{
	int	i;

	if (!entries)
		return (-1);
	i = 0;
	while (i < rows)
	{
		if (entries[i])
			free(entries[i]);
		i++;
	}
	free(entries);
	return (0);
}
