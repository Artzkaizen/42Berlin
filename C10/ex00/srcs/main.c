/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:51:00 by chuezeri          #+#    #+#             */
/*   Updated: 2024/10/04 11:56:43 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int	main(int argc, char *argv[])
{
	int		fd;
	int		bytes_read;
	char	buffer[BUFFER_SIZE];

	if (argc == 1)
		write(1, "File name missing.\n", 20);
	else if (argc > 2)
		write(1, "Too many arguments.\n", 21);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			write(2, "Cannot read file.\n", 21);
			return (1);
		}
		bytes_read = read(fd, buffer, 1);
		while (bytes_read)
		{
			write(1, buffer, 1);
			bytes_read = read(fd, buffer, 1);
		}
		close(fd);
	}
}
