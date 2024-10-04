/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:53:59 by alneuman          #+#    #+#             */
/*   Updated: 2024/09/15 23:01:03 by alneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict_init.h"
#include "defaults.h"
#include <stdlib.h>
#include "utils.h"

t_dict	dict_create_default(void)
{
	t_dict	new_dict;

	new_dict = malloc(sizeof(*new_dict));
	if (!new_dict)
		return (NULL);
	new_dict->keys_100 = g_def_keys_100;
	new_dict->vals_100 = g_def_vals_100;
	new_dict->keys_pow_1000 = g_def_keys_pow_1000;
	new_dict->vals_pow_1000 = g_def_vals_pow_1000;
	new_dict->max_pow_1000 = NUM_KEYS_1000 - 1;
	new_dict->is_default = 1;
	return (new_dict);
}

t_dict	dict_create(void)
{
	t_dict	new_dict;
	int		i;

	new_dict = malloc(sizeof(*new_dict));
	if (!new_dict)
		return (NULL);
	new_dict->keys_100 = g_def_keys_100;
	new_dict->keys_pow_1000 = g_def_keys_pow_1000;
	new_dict->max_pow_1000 = NUM_KEYS_1000 - 1;
	new_dict->vals_100 = malloc(sizeof(*new_dict->vals_100) 
			* (NUM_KEYS_100 + 1));
	if (!new_dict->vals_100)
		return (NULL);
	i = 0;
	while (i < NUM_KEYS_100 + 1)
		new_dict->vals_100[i++] = NULL;
	new_dict->vals_pow_1000 = malloc(sizeof(*new_dict->vals_pow_1000) 
			* (NUM_KEYS_1000 + 1));
	if (!new_dict->vals_pow_1000)
		return (NULL);
	i = 0;
	while (i < NUM_KEYS_1000 + 1)
		new_dict->vals_pow_1000[i++] = NULL;
	new_dict->is_default = 0;
	return (new_dict);
}

void	dict_destroy(t_dict dict)
{
	int	i;

	if (dict->is_default)
	{
		free(dict);
		return ;
	}
	i = 0;
	while (i < NUM_KEYS_100 + 1)
	{
		if (dict->vals_100[i])
			free(dict->vals_100[i]);
		i++;
	}
	free(dict->vals_100);
	while (i < NUM_KEYS_1000 + 1)
	{
		if (dict->vals_pow_1000[i])
			free(dict->vals_pow_1000[i]);
		i++;
	}
	free(dict->vals_pow_1000);
	free(dict);
}
