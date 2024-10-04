/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:22:37 by alneuman          #+#    #+#             */
/*   Updated: 2024/09/18 19:14:06 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"
#include "read_map.h"
#include <unistd.h>

#define TMP_MAP ".~map.tmp"

int main(int argc, char **argv)
{
	int i;

	if (argc == 1)
	{
		read_and_create_file("", TMP_MAP);
		if (run_alg(TMP_MAP) == -2)
			write(2, "map error\n", 10);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (run_alg(argv[i]) == -2)
			write(1, "map error\n", 10);
		if (i != argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
