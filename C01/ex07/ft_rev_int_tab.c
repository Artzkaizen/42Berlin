/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:41:21 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/03 18:33:53 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	pos;
	int	temp;

	pos = 0;
	while (pos < size / 2)
	{
		temp = tab[pos];
		tab[pos] = tab[size - pos - 1];
		tab[size - pos - 1] = temp;
		pos++;
	}
}

int	main(void)
{
	int	i;
	int	tab[5] = {189, 43, 93, 0, -5};

	ft_rev_int_tab(tab, 5);
	i = 0;
	while (i < 5)
	{
		printf("%d ", tab[i]);
		i++;
	}
	return (0);
}
