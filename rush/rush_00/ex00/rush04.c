/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:05:25 by chuezeri          #+#    #+#             */
/*   Updated: 2024/10/04 10:31:21 by chuezeri         ###   ########.fr       */
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
			if ((height == 1 && width == 1) || (width == x && height == y))
				ft_putchar('A');
			else if ((height == y && (width == 1 || width == x))
				|| (width == x && height == 1))
				ft_putchar('C');
			else if (width == 1 || width == x || height == 1 || height == y)
				ft_putchar('B');
			else
				ft_putchar(' ');
			width++;
		}
		height++;
		ft_putchar('\n');
	}
}
