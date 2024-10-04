/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:49:07 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/03 13:11:15 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	count;
	int	current;

	count = 0;
	while (count < size - 1)
	{
		current = 0;
		while (current < size - 1)
		{
			if (tab[current] > tab[current + 1])
			{
				temp = tab[current + 1];
				tab[current + 1] = tab[current];
				tab[current] = temp;
			}
			current++;
		}
		count++;
	}
}

int	main(void)
{
	int	tab[] = {64, 34, 25, 12, 22, 11, 90,232, 42342, 5235};
	int	size = sizeof(tab) / sizeof(tab[0]);
	int	i;

	printf("Original array:\n");
	for (i = 0; i < size; i++)
		printf("%d ", tab[i]);
	printf("\n");

	ft_sort_int_tab(tab, size); // Call the sorting function

	printf("Sorted array:\n");
	for (i = 0; i < size; i++)
		printf("%d ", tab[i]);
	printf("\n");
	return (0);
}