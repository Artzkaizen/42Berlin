/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:58:05 by chuezeri          #+#    #+#             */
/*   Updated: 2024/08/31 19:26:31 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	power(int base, int exp)
{
	int	result;

	result = 1;
	while (exp > 0)
	{
		result *= base;
		exp--;
	}
	return (result);
}

void	print_valid_comb(char *digits, int n, int *is_first)
{
	int	i;
	int	is_valid;

	is_valid = 1;
	i = 0;
	while (i < n - 1)
	{
		if (digits[i] >= digits[i + 1])
		{
			is_valid = 0;
			break ;
		}
		i++;
	}
	if (is_valid)
	{
		if (!*is_first)
			write(1, ", ", 2);
		write(1, digits, n);
		*is_first = 0;
	}
}

void	ft_print_combn(int n)
{
	int		i;
	int		j;
	int		temp;
	int		is_first;
	char	digit[10];

	i = 0;
	is_first = 1;
	while (i < power(10, n))
	{
		j = 0;
		temp = i;
		while (j < n)
		{
			digit[n - j - 1] = '0' + temp % 10;
			temp /= 10;
			j++;
		}
		print_valid_comb(digit, n, &is_first);
		i++;
	}
}
