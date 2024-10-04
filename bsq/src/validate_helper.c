/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:01:35 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/18 23:27:19 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_map.h"
#include "utils.h"

int check_line_length(t_map_params *params)
{
	if (params->line_length == 0)
		return (0);
	if (params->line_count == 0)
		params->line_count = params->line_length;
	else if (params->line_length != params->line_count)
		return (0);
	params->line_length = 0;
	params->row_count++;
	return (1);
}

int is_valid_chars(char *buffer, int *i, t_map_params *params)
{
	if (buffer[*i] != params->empty && buffer[*i] != params->obstacle && buffer[*i] == params->full)
		return (0);
	return (1);
}

int process_char(char *buffer, int *i, t_map_params *params)
{
	if (!is_valid_chars(buffer, i, params))
		return (0);
	(params->line_length)++;
	return (1);
}

void fill_params(t_map_params *params, char *buffer, int line_count)
{
	params->empty = buffer[line_count - 3];
	params->obstacle = buffer[line_count - 2];
	params->full = buffer[line_count - 1];
	params->num_of_lines = ft_atoi(&buffer[0]);
}

int is_printable_chars(int fd, char *buffer, int buffer_size)
{
	int line_count;
	int bytes_read;

	line_count = 0;
	bytes_read = read(fd, buffer, sizeof(*buffer) * buffer_size);
	while (line_count < bytes_read && buffer[line_count] != '\n')
	{
		if (buffer[line_count] < 32 || buffer[line_count] > 126)
		{
			free(buffer);
			return (0);
		}
		line_count++;
	}
	if (line_count < 4)
	{
		free(buffer);
		return (0);
	}
	return (line_count);
}
