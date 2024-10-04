/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:49:22 by alneuman          #+#    #+#             */
/*   Updated: 2024/09/15 23:40:09 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_FILE_H
# define READ_FILE_H

# include "dict_init.h"

int	get_dict(t_dict dict, const char *dict_file);
int	get_line_length(const int fh);
int	get_max_line_length(const char *dict_file);
int	get_line(const int fh, char *buff);
int	validate_line(char *line);
int	ft_isdigit(char c);
int	get_key(char *key_buffer, char *line);
int	get_val(char *val_buffer, char *line);

#endif //READ_FILE_H
