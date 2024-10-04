/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:40:59 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/03 16:00:23 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] >= 97 && str[index] <= 122)
		{
			str[index] -= 32;
		}
		index++;
	}
	return (str);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char str[] = {"hello"};

// 	printf("uppercase %s", ft_strupcase(str));
// }
