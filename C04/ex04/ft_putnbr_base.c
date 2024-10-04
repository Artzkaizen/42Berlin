/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:40:03 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/09 18:41:30 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_valid_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i + 1] && str[i])
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
	return (i + 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		radix;

	radix = ft_is_valid_base(base);
	if (radix > 1)
	{
		if (nbr >= radix)
			ft_putnbr_base(nbr / radix, base);
		else if (nbr < 0)
		{
			write(1, "-", 1);
			if (nbr <= -radix)
				ft_putnbr_base(((nbr / radix) * -1), base);
			nbr = (nbr % radix) * -1;
		}
		write (1, &base[nbr % radix], 1);
	}
}
