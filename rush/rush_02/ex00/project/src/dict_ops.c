/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:31:35 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/15 22:19:29 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict_init.h"
// #include "defaults.h"
#include <stdlib.h>
#include "utils.h"

// number should be between 0 and 100 inclusively
char	*dict_lookup_100_int(t_dict dict, int number)
{
	char	num_str[3];

	if (number == 100)
		return (dict_lookup_100_str(dict, "100"));
	else if (number > 9)
	{
		num_str[0] = number / 10 + '0';
		num_str[1] = number % 10 + '0';
		num_str[2] = '\0';
	}
	else
	{
		num_str[0] = number % 10 + '0';
		num_str[1] = '\0';
	}
	return (dict_lookup_100_str(dict, num_str));
}

char	*dict_lookup_100_str(t_dict dict, char *key)
{
	int	i;

	i = 0;
	while (dict->keys_100[i])
	{
		if (!ft_strcmp(dict->keys_100[i], key))
			return (dict->vals_100[i]);
		i++;
	}
	return (NULL);
}

char	*dict_lookup_pow_1000(t_dict dict, int pow_1000)
{
	return (dict->vals_pow_1000[pow_1000]);
}

// return values:
// success					-> 0
// out of memory			-> -1
// key not in dict			-> -2
// key already has value	-> -3
int	dict_write(t_dict dict, char *key, char *value)
{
	int	i;
	int	length_value;

	i = 0;
	while (dict->keys_100[i])
	{
		if (!ft_strcmp(dict->keys_100[i], key))
		{
			length_value = ft_strlen(value);
			if (dict->vals_100[i])
				return (-3);
			dict->vals_100[i] = malloc(sizeof(*dict->vals_100[i]) 
					* (length_value + 1));
			if (!dict->vals_100[i])
				return (-1);
			ft_strcpy(dict->vals_100[i], value);
			return (0);
		}
	}
	while (dict->keys_pow_1000[i])
	{
		if (!ft_strcmp(dict->keys_pow_1000[i], key))
		{
			length_value = ft_strlen(value);
			if (dict->vals_pow_1000[i])
				return (-3);
			dict->vals_pow_1000[i] = malloc(sizeof(*dict->vals_pow_1000[i]) 
					* (length_value + 1));
			if (!dict->vals_pow_1000[i])
				return (-1);
			ft_strcpy(dict->vals_pow_1000[i], value);
			return (0);
		}
	}
	return (-2);
}
