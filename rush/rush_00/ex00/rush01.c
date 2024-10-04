/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:09:59 by chuezeri          #+#    #+#             */
/*   Updated: 2024/10/04 10:36:42 by chuezeri         ###   ########.fr       */
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
		while (width <= x)
		{
			if ((height == 1 && width == 1) || (width == x && height == y))
				ft_putchar('/');
			else if ((height == y && (width == 1 || width == x))
				|| (width == x && height == 1))
				ft_putchar('\\');
			else if (width == 1 || width == x || height == 1 || height == y)
				ft_putchar('*');
			else
				ft_putchar(' ');
			width++;
		}
		height++;
		ft_putchar('\n');
	}
}
