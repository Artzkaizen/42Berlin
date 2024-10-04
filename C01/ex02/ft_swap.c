/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:19:40 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/03 09:15:49 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *b;
	*b = *a;
	*a = temp;
}
// int	main(void)
// {
// 	int num1 = 150;
// 	int num2 = 498;
// 	int *a = &num1;
// 	int *b = &num2;
// 	ft_swap(a, b);
// }