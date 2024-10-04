/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 09:20:18 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/10 18:23:39 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	is_valid_char(char c)
{
	char	max;

	max = '0' + GRID_SIZE;
	return ((c >= '1' && c <= max) || c == ' ');
}

static int	process_input(char *str, int *clues)
{
	int	i;
	int	ci;

	i = 0;
	ci = 0;
	while (str[i])
	{
		if (!is_valid_char(str[i]))
		{
			ft_putstr("Error\n");
			return (0);
		}
		if (i % 2 == 0 && str[i] != ' ' && !(ci >= GRID_SIZE * 4))
		{
			clues[ci] = str[i] - '0';
			ci++;
		}
		i++;
	}
	if (ci != GRID_SIZE * 4 || i != ((GRID_SIZE * 4) * 2) - 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}

int	*valid_input(char *str)
{
	int	*clues;

	clues = (int *)malloc((GRID_SIZE * 4) * sizeof(int));
	if (!clues)
		return (NULL);
	if (process_input(str, clues) == 0)
	{
		free(clues);
		return (NULL);
	}
	return (clues);
}
