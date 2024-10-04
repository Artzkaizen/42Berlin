/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:30:54 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/04 14:55:17 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_is_none(char *str)
{
	char	c[3];

	c[0] = '\\';
	c[1] = '0';
	if (*str <= 9)
	{
		c[2] = *str + '0';
		write (1, c, 3);
	}
	else if (*str >= 9 && *str <= 15)
	{
		c[2] = *str + 87;
		write(1, c, 3);
	}
	else if (*str == 127)
	{
		c[1] = '7';
		c[2] = 'f';
		write(1, c, 3);
	}
	else
		write(1, str, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		count;

	count = 0;
	while (str[count])
	{
		ft_print_is_none(&str[count]);
		count++;
	}
}
// #include <stdio.h>
// int	main(void)
// {
// 	char word[] = {"Coucou\ntu vas bien ? \a \r \t"};

// 	ft_putstr_non_printable(word);
// }
