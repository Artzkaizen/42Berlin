/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:11:42 by alneuman          #+#    #+#             */
/*   Updated: 2024/09/18 23:34:29 by alneuman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_MAP_H
# define READ_MAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

typedef struct s_map_params {
	char	empty;
	char	obstacle;
	char	full;
	int		line_length;
	int		row_count;
	int		line_count;
	int		num_of_lines;
}	t_map_params;

int	get_line_length(const int fh);
int	copy_file_contents(int fd_in, int fd_out);
int	open_file(const char *file, int read);
int	process_char(char *buffer, int *i, t_map_params *params);
int	is_valid_map(const char *filename, t_map_params	*params);
int	validate_map_line(char *buffer, int bytes_read, t_map_params *params);
int	read_and_create_file(const char *input_file, const char *output_file);

#endif //READ_FILE_H
