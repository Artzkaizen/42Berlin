/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:57:35 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/18 23:22:54 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_map.h"
#include "utils.h"

int		check_line_length(t_map_params *params);
int		is_valid_chars(char *buffer, int *i, t_map_params *params);
int		is_printable_chars(int fd, char *buffer, int buffer_size);
void	fill_params(t_map_params *params, char *buffer, int line_count);

int	validate_first_line(int fd, t_map_params *params, int buffer_size)
{
	int		line_count;
	char	*buffer;

	line_count = 0;
	buffer = malloc(buffer_size);
	if (!buffer)
		return (0);
	line_count = is_printable_chars(fd, buffer, buffer_size);
	if (!line_count)
	{
		free(buffer);
		return (0);
	}
	fill_params(params, buffer, line_count);
	if (params->empty != params->obstacle && params->empty != params->full
		&& params->obstacle != params->full)
	{
		free(buffer);
		return (line_count);
	}
	free(buffer);
	return (0);
}

int	validate_map_line(char *buffer, int bytes_read, t_map_params *params)
{
	int	i;

	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
		{
			if (!check_line_length(params))
				return (0);
		}
		else
		{
			if (!process_char(buffer, &i, params))
				return (0);
		}
		i++;
	}
	return (1);
}

// Memory error -> -1;
int	open_and_validate_first_line(const char *filename, t_map_params *params)
{
	int	fd;
	int	first_line_length;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	first_line_length = get_line_length(fd);
	close(fd);
	if (fd == -1)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (validate_first_line(fd, params, first_line_length) == 0)
		return (-1);
	if (first_line_length == 0)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (fd);
}

int	process_map_content(int fd, const char *filename, t_map_params *params)
{
	int		bytes_read;
	int		buffsize;
	char	*buffer;

	buffsize = get_line_length(fd);
	buffer = malloc(buffsize);
	if (!buffer)
		return (0);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	get_line_length(fd);
	bytes_read = read(fd, buffer, buffsize);
	while (bytes_read > 0)
	{
		if (validate_map_line(buffer, bytes_read, params) == 0)
		{
			free(buffer);
			return (0);
		}
		bytes_read = read(fd, buffer, buffsize);
	}
	free(buffer);
	return (1);
}

//printf("empty = %c\n", params->empty); 
//printf("obstacle = %c\n", params->obstacle); 
//printf("full = %c\n", params->full); 
//printf("line_length = %d\n", params->line_length); 
//printf("row_count = %d\n", params->row_count); 
//printf("line_count = %d\n", params->line_count); 
//printf("num_of_lines = %d\n", params->num_of_lines); 
//putchar('\n');
int	is_valid_map(const char *filename, t_map_params *params)
{
	int	fd;

	fd = open_and_validate_first_line(filename, params);
	if (fd == -1)
		return (0);
	fd = open(filename, O_RDONLY);
	get_line_length(fd);
	params->row_count = 0;
	if (!process_map_content(fd, filename, params))
	{
		close(fd);
		return (0);
	}
	close(fd);
	if (!(params->empty != params->obstacle && params->empty != params->full
			&& params->obstacle != params->full))
		return (0);
	if (params->line_count > 0 && params->line_length == 0
		&& params->row_count == params->num_of_lines)
	{
		close(fd);
		return (1);
	}
	return (0);
}
