/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:33:54 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/15 21:25:58 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "put_nums.h"
#include "dict_init.h"
#include "utils.h"

int	is_valid_input(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (sign != 0)
			return (0);
		if (str[i] == '-')
			return (0);
		else
			sign++;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i])
		return (0);
	return (1);
}

char	*trim_and_rev_str(char *str)
{
	int		i;
	int		j;
	int		length;
	char	*reverse;

	i = 0;
	length = ft_strlen(str);
	reverse = malloc(sizeof(char) * ft_strlen(str) + 3);
	if (!reverse)
		return (NULL);
	while ((str[i] == 32) || (str[i] <= 13 && str[i] >= 9))
		i++;
	j = 0;
	if (str[i] == '+')
		i++;
	length--;
	while (length >= 0 && (str[length] >= '0' && str[length] <= '9'))
		reverse[j++] = str[length--];
	reverse[j] = '\0';
	reverse[j + 1] = '\0';
	reverse[j + 2] = '\0';
	return (reverse);
}
