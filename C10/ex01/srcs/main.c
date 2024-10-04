/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:51:00 by chuezeri          #+#    #+#             */
/*   Updated: 2024/10/04 12:55:58 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#define BUFFER_SIZE 29800

int	main(int argc, char *argv[])
{
	int		i;
	int		fd;
	int		bytes_read;
	char	buffer[BUFFER_SIZE];

	i = 0;
	while (i < argc)
	{
		if (argc > 1)
			fd = open(argv[++i], O_RDONLY);
		else
			fd = STDIN_FILENO;
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
