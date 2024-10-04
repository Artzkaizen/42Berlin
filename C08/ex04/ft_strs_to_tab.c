/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 15:20:04 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/18 11:55:09 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	count;

	count = 0;
	while (src[count])
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

void	fill_struct(t_stock_str *array, int i, int size, char *av)
{
	array[i].size = size;
	array[i].str = &av[i];
	ft_strcpy(array[i].copy, &av[i]);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			len;
	t_stock_str	*array;

	array = malloc((sizeof(t_stock_str) * ac) + 1);
	if (!array)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		array[i].copy = malloc((sizeof(char) * len) + 1);
		array[i].size = len;
		array[i].str = av[i];
		ft_strcpy(array[i].copy, av[i]);
		i++;
	}
	array[ac].str = 0;
	return (array);
}

// #include <stdio.h>
// #include <unistd.h>
// void ft_putstr(char *str)
// {
// 	while (*str)
// 	{
// 		write(1, str, 1);
// 		str++;
// 	}
// }

// void ft_putnbr(int nb)
// {
// 	char c;

// 	if (nb == -2147483648)
// 	{
// 		write(1, "-2", 2);
// 		nb = 147483648;
// 	}
// 	if (nb < 0)
// 	{
// 		nb *= -1;
// 		write(1, "-", 1);
// 	}
// 	if (nb < 10)
// 	{
// 		c = nb + 48;
// 		write(1, &c, 1);
// 	}
// 	else
// 	{
// 		ft_putnbr(nb / 10);
// 		ft_putnbr(nb % 10);
// 	}
// }
// void ft_show_tab(struct s_stock_str *par)
// {
// 	int i;

// 	i = 0;
// 	while (par[i].str)
// 	{
// 		ft_putstr(par[i].str);
// 		ft_putstr("\n");
// 		ft_putnbr(par[i].size);
// 		ft_putstr("\n");
// 		ft_putstr(par[i].copy);
// 		ft_putstr("\n");
// 		i++;
// 	}
// }

// int main(void)
// {
// 	char *array[] = {"Hello", "People", "From", "The", "Other", "Side"};
// 	ft_show_tab(ft_strs_to_tab(6, array));
// }