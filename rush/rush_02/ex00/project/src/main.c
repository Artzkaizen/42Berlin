/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:44:08 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/15 12:58:49 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "dict_init.h"
#include "validate.h"
#include "put_nums.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

int		is_valid_input(char *str);
char	*trim_and_rev_str(char *str);
int		get_dict(t_dict dict, const char *dict_file);
// void	ar

int	main(int argc, char **argv)
{
	t_dict	dict;
	char	*num_rev;

	num_rev = NULL;
	dict = NULL;
	if (argc != 1 && argc <= 3 && is_valid_input(argv[argc - 1]))
	{
		if (argc == 2)
			dict = dict_create_default();
		else if (argc == 3)
		{
			dict = dict_create();
			if (!dict)
			{
				ft_putstr("Error\n");
				return (0);
			}
			get_dict(dict, argv[1]);
		}
		num_rev = trim_and_rev_str(argv[argc - 1]);
		if (!num_rev)
		{
			ft_putstr("Error\n");
			return (0);
		}
		print_num_in_words(num_rev, dict);
	}
	else
		ft_putstr("Error");
	ft_putstr("\n");
	dict_destroy(dict);
	free(num_rev);
	return (0);
}
