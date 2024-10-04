/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:31:55 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/18 10:05:56 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

int	is_in_base(char *str, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != *str)
		i++;
	if (base[i] == '\0')
		return (-1);
	return (i);
}

int	ft_is_valid_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+' 
			|| (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
			return (0);
		j = i + 1;
		while (str[i] && str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nb;
	int	sign;
	int	radix;

	nb = 0;
	sign = 1;
	radix = ft_is_valid_base(base);
	if (radix > 1)
	{
		while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
			str++;
		while (*str == '-' || *str == '+')
		{
			if (*str == '-')
				sign *= -1;
			str++;
		}
		while (is_in_base(str, base) >= 0)
		{
			nb = nb * radix + is_in_base(str, base);
			str++;
		}
	}
	return (nb *= sign);
}

void	ft_putnbr_base(int nbr, char *base, char *string, int *i)
{
	int	radix;

	radix = ft_is_valid_base(base);
	if (radix > 1)
	{
		if (nbr >= radix)
			ft_putnbr_base(nbr / radix, base, string, i);
		else if (nbr < 0)
		{
			string[(*i)++] = '-';
			if (nbr <= -radix)
				ft_putnbr_base(((nbr / radix) * -1), base, string, i);
			nbr = (nbr % radix) * -1;
		}
		string[(*i)++] = base[nbr % radix];
	}
	string = 0;
}

// #include <stdio.h>
// char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
// int	main(void)
// {
// 	char	*base_to;
// 	char	*base_from;
// 	char	*nbr;

// 	nbr = "-80000000";
// 	base_to = "0123456789";
// 	base_from = "0123456789ABCDEF";
// 	printf("convert: %s\n", ft_convert_base(nbr, base_from, base_to));
// }
