/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:28:09 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/18 22:29:43 by alneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_map.h"
#include "utils.h"

int	open_file(const char *file, int read)
{
	int	fd;

	if (read)
		fd = open(file, O_RDONLY);
	else
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	return (fd);
}

int	copy_file_contents(int fd_in, int fd_out)
{
	char	buffer;
	int		bytes_read;
	int		bytes_written;

	bytes_read = read(fd_in, &buffer, 1);
	while (bytes_read > 0)
	{
		bytes_written = write(fd_out, &buffer, 1);
		if (bytes_written != bytes_read)
			return (-1);
		bytes_read = read(fd_in, &buffer, 1);
	}
	if (bytes_read == -1)
		return (-1);
	return (0);
}

int	get_line_length(const int fh)
{
	char	buff;
	int		read_byte;
	int		length;

	read_byte = read(fh, &buff, 1);
	if (read_byte == 0)
		return (0);
	length = 1;
	while (read_byte && buff != '\n')
	{
		length++;
		read_byte = read(fh, &buff, 1);
	}
	return (length);
}

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	read_and_create_file(const char *input_file, const char *output_file)
{
	int	fd_in;
	int	fd_out;
	int	result;

	if (ft_strlen(input_file))
		fd_in = open_file(input_file, 1);
	else
		fd_in = STDIN_FILENO;
	fd_out = open_file(output_file, 0);
	if (fd_out == -1 || fd_in == -1)
	{
		if (fd_in)
			close(fd_in);
		else if (fd_out)
			close(fd_in);
		return (-1);
	}
	result = copy_file_contents(fd_in, fd_out);
	close(fd_in);
	close(fd_out);
	return (result);
}
