/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:05:03 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/04 11:29:32 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_alpha_numeric(char *str)
{
	if (*str >= 65 && *str <= 90)
		return (1);
	else if (*str >= 97 && *str <= 122)
		return (2);
	else if (*str >= 48 && *str <= 57)
		return (3);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	next;
	int	current;

	i = 0;
	while (str[i] != '\0')
	{
		next = ft_is_alpha_numeric(&str[i - 1]);
		current = ft_is_alpha_numeric(&str[i]);
		if (current && next == 0)
		{
			if (current != 3 && current != 1)
				str[i] -= 32;
		}
		else if (current == 1 && next)
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char str[] = {"saLut, coMmenT ?? ' "};

// 	printf("%s", ft_strcapitalize(str));
// }
