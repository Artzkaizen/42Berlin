/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:28:39 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/01 16:15:13 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	width;
	int	height;

	height = 1;
	while (height <= y && height > 0 && width > 0)
	{
		width = 1;
		while (width <= x && height > 0 && width > 0)
		{
			if ((width == 1) && (height == 1 || height == y))
				ft_putchar('A');
			else if ((width == x) && (height == 1 || height == y))
				ft_putchar('C');
			else if (height == 1 || height == y || width == 1 || width == x)
				ft_putchar('B');
			else
				ft_putchar(' ');
			width++;
		}
		height++;
		ft_putchar('\n');
	}
}
