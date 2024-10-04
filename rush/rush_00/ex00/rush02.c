/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 19:28:39 by chuezeri          #+#    #+#             */
/*   Updated: 2024/10/04 10:37:52 by chuezeri         ###   ########.fr       */
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
			if ((width == 1 || width == x) && height == 1)
				ft_putchar('A');
			else if ((width == 1 || width == x) && height == y)
				ft_putchar('C');
			else if (height == 1 || height == y || width == x || width == 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			width++;
		}
		height++;
		write(1, "\n", 1);
	}
}
