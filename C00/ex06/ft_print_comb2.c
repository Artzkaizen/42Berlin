/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:49:10 by chuezeri          #+#    #+#             */
/*   Updated: 2024/08/31 17:56:16 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		i;
	int		j;
	char	digits[5];

	i = 0;
	while (i <= 99)
	{
		j = i + 1;
		while (j <= 99)
		{
			digits[0] = '0' + (i / 10);
			digits[1] = '0' + (i % 10);
			digits[2] = ' ';
			digits[3] = '0' + (j / 10);
			digits[4] = '0' + (j % 10);
			write (1, digits, 5);
			if (i != 98 || j != 99)
			{
				write(1, ", ", 2);
			}
			j++;
		}
		i++;
	}
}
