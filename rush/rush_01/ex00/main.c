/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 09:20:32 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/08 14:59:23 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char **argv)
{
	int	**grid;
	int	*valid_clues;

	if (argc == 2)
	{
		valid_clues = valid_input(argv[1]);
		if (!valid_clues)
			return (1);
		grid = create_grid();
		if (!grid)
		{
			ft_putstr("Error\n");
			free(valid_clues);
			return (1);
		}
		if (solve_grid(grid, valid_clues, 0, 0))
			print_grid(grid);
		else
			ft_putstr("Error\n");
		free_grid(grid);
		free(valid_clues);
	}
	return (0);
}
