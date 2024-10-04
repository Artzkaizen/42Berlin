/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 17:42:31 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/03 11:19:03 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp;

	temp = *a / *b;
	*b = *a % *b;
	*a = temp;
}
// int	main(void)
// {
// 	int num1 = 9;
// 	int num2 = 7;

// 	int *a = &num1;
// 	int *b = &num2;
// 	ft_ultimate_div_mod(a, b);
// }