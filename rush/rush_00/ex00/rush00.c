/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:11:33 by chuezeri          #+#    #+#             */
/*   Updated: 2024/10/04 10:38:11 by chuezeri         ###   ########.fr       */
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
			if ((width == 1) && (height == 1 || height == y))
				ft_putchar('o');
			else if ((width == x) && (height == 1 || height == y))
				ft_putchar('o');
			else if (width == 1 || width == x)
				ft_putchar('|');
			else if (height == 1 || height == y)
				ft_putchar('-');
			else
				ft_putchar(' ');
			width++;
		}
		height++;
		ft_putchar('\n');
	}
}
