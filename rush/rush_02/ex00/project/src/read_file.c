/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:46:47 by alneuman          #+#    #+#             */
/*   Updated: 2024/09/15 23:37:01 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/// TODO cater for file reading errors (e.g. trying to read dirs)
// #include "defaults.h"
#include "dict_init.h"
#include "read_file.h"
#include "utils.h"
#include <sys/stat.h>	//open
#include <fcntl.h> //open
#include <unistd.h>		//read, close
#include <stdlib.h>		//malloc, free
#include <errno.h>		//

#define NUM_KEYS_100 29
#define NUM_KEYS_1000 12

static int	rest_is_valid(char *line);
static int	ft_is_printable(char c);
static int	dict_write(t_dict dict, char *key, char *value);
static int	dict_write_100(t_dict dict, char *key, char *value);
int			dict_write_pow_1000(t_dict dict, char *key, char *value);
int			dict_populate(t_dict dict, int fh, int max_line_length);
int			dict_validate(t_dict dict);
static int	get_key_helper(char *key_buffer, char *line);

// return values:
// success		-> 0
// outof memory -> -1
int	malloc_3(void *p1, void *p2, void *p3, unsigned int size)
{
	p1 = malloc(size);
	if (!p1)
		return (-1);
	p2 = malloc(size);
	if (!p2)
	{
		free(p1);
		return (-1);
	}
	p3 = malloc(size);
	if (!p3)
	{
		free(p1);
		free(p2);
		return (-1);
	}
	return (0);
}

// return values:
// success			-> 0
// out of memory	-> -1
// dict error		-> -2
int	get_dict(t_dict dict, const char *dict_file)
{
	int	max_line_length;
	int	fh_open;
	int	error;

	max_line_length = get_max_line_length(dict_file);
	fh_open = open(dict_file, O_RDWR); 
	if (fh_open < 0 && errno == EISDIR)
		return (-2);
	fh_open = open(dict_file, O_RDONLY);
	if (fh_open < 0)
		return (-2);
	error = dict_populate(dict, fh_open, max_line_length);
	if (error)
		return (error);
	if (!dict_validate(dict))
		return (-2);
	return (0);
}

// return values
// valid	-> 1
// invalid	-> 0
int	dict_validate(t_dict dict)
{
	int	i;

	i = 0;
	while (i < NUM_KEYS_100)
	{
		if (dict->vals_100[i++] == NULL)
			return (-2);
	}
	i = 0;
	while (i < NUM_KEYS_1000)
	{
		if (dict->vals_pow_1000[i++] == NULL)
			return (-2);
	}
	return (0);
}

// return values
// success 			-> 0
// out of memory	-> -1
// duplicate		-> -2
int	dict_populate(t_dict dict, int fh, int max_line_length)
{
	char	*line_buffer;
	char	*key_buffer;
	char	*val_buffer;
	int		not_eof;
	int		dict_write_error;

	key_buffer = NULL;
	val_buffer = NULL;
	line_buffer = NULL;
	if (malloc_3(line_buffer, key_buffer, val_buffer,
			sizeof(*line_buffer) * max_line_length))
		return (-1);
	not_eof = get_line(fh, line_buffer);
	while (not_eof)
	{
		if (get_key(key_buffer, line_buffer))
		{
			get_val(val_buffer, line_buffer);
			dict_write_error = dict_write(dict, key_buffer, val_buffer);
			if (dict_write_error == -1)
				return (-1);
			else if (dict_write_error == -2)
				return (-2);
		}
		not_eof = get_line(fh, line_buffer);
	}
	return (0);
}

// return values
// success			-> 0
// out of memory	-> -1
// duplicate		-> -2
// key not found	-> -3
static int	dict_write(t_dict dict, char *key, char *value)
{
	int	error;

	error = dict_write_100(dict, key, value);
	if (error && error != -1)
		return (error);
	error = dict_write_pow_1000(dict, key, value);
	return (error);
}

// return values
// success			-> 0
// out of memory	-> -1
// duplicate		-> -2
// key not found	-> -3
int	dict_write_100(t_dict dict, char *key, char *value)
{
	int	i;

	i = 0;
	while (dict->keys_100[i])
	{
		if (!ft_strcmp(key, dict->keys_100[i]))
		{
			if (dict->vals_100[i])
				return (-2);
			dict->vals_100[i] = malloc(sizeof(*dict->vals_100[i])
					* (ft_strlen(value) + 1));
			if (!dict->vals_100[i])
				return (-1);
			ft_strcpy(dict->vals_100[i], value);
			return (0);
		}
	}
	return (-3);
}

// return values
// success			-> 0
// out of memory	-> -1
// duplicate		-> -2
// key not found	-> -3
int	dict_write_pow_1000(t_dict dict, char *key, char *value)
{
	int	i;

	i = 0;
	while (dict->keys_pow_1000[i])
	{
		if (!ft_strcmp(key, dict->keys_pow_1000[i]))
		{
			if (dict->vals_pow_1000[i])
				return (-2);
			dict->vals_pow_1000[i] = malloc(sizeof(*dict->vals_pow_1000[i])
					* (ft_strlen(value) + 1));
			if (!dict->vals_pow_1000[i])
				return (-1);
			ft_strcpy(dict->vals_pow_1000[i], value);
			return (0);
		}
	}
	return (-3);
}

int	get_val(char *val_buffer, char *line)
{
	while (*line != ':')
		line++;
	line++;
	while (*line == ' ')
		line++;
	*val_buffer = '\0';
	while (*line)
	{
		if (*val_buffer == ' ')
			val_buffer++;
		while (*line && *line != ' ')
			*val_buffer++ = *line++;
		if (!*line)
		{
			*val_buffer = '\0';
			return (0);
		}
		*val_buffer = ' ';
		while (*line && *line == ' ')
			line++;
	}
	if (*val_buffer == ' ')
		*val_buffer = '\0';
	return (0);
}

// make this function also validate
// return values
// valid pair	-> 1
// else			-> 0
int	get_key(char *key_buffer, char *line)
{
	int		minus_at_start;

	minus_at_start = 0;
	while (*line == ' ' || (*line >= 9 && *line <= 13))
		line++;
	if (*line == '-')
	{
		minus_at_start = 1;
		line++;
	}
	else if (*line != '+' && !ft_isdigit(*line))
		return (0);
	else if (*line == '+')
		line++;
	while (*line == '0')
		line++;
	if (!ft_isdigit(*line))
		get_key_helper(key_buffer, line);
	else if (minus_at_start)
		return (0);
	while (ft_isdigit(*line))
		*key_buffer++ = *line++;
	*key_buffer = '\0';
	return (rest_is_valid(line));
}

static int	get_key_helper(char *key_buffer, char *line)
{
	if (*(line - 1) != '0')
		return (0);
	else
	{
		key_buffer[0] = '0';
		key_buffer[1] = '\0';
		return (rest_is_valid(line));
	}
}

// goes with get key
static int	rest_is_valid(char *line)
{
	while (*line && *line != ':')
		line++;
	if (*line != ':')
		return (0);
	line++;
	while (*line)
	{
		if (!ft_is_printable(*line++))
			return (0);
	}
	return (1);
}

static int	ft_is_printable(char c)
{
	return (c >= ' ' && c <= '~');
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

// return length of line
int	get_line(const int fh, char *buff)
{
	int		read_byte;
	int		length;

	length = 0;
	read_byte = read(fh, buff, 1);
	while (read_byte && *buff++ != '\n')
	{
		length++;
		read_byte = read(fh, buff, 1);
	}
	if (*(buff - 1) == '\n')
		*(buff - 1) = '\0';
	return (length);
}

//returns length of line
//counts '\n'
//so we know, returnvalue 0
//is EOF
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

// tries to determine the length of the longest line of interest in dict_file
// line of interest = line in the correct format
// return values
// cannot read dict	-> -1
// success			-> length of longest line of interest
int	get_max_line_length(const char *dict_file)
{
	int		fh_open;
	int		current_line;
	int		max_line;

	fh_open = open(dict_file, O_RDONLY);
	if (fh_open < 0)
		return (-1);
	max_line = 0;
	current_line = get_line_length(fh_open);
	while (current_line)
	{
		if (current_line > max_line)
			max_line = current_line;
		current_line = get_line_length(fh_open);
	}
	close(fh_open);
	return (max_line);
}

// #include <stdio.h>

// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	argc = get_max_line_length(argv[1]);
// 	printf("%d\n", argc);
// 	char *buff = malloc(sizeof(*buff) * argc);
// 	char *key_buff = malloc(sizeof(*key_buff) * argc);
// 	char *val_buff = malloc(sizeof(*val_buff) * argc);
// 	int fh_open = open(argv[1], O_RDONLY);
// 	if (fh_open < 0)
// 		return (-1);
// 	get_line(fh_open, buff);
// 	if (!get_key(key_buff, buff))
// 		puts("Error\n");
// 	else
// 	{
// 		get_val(val_buff, buff);
// 		puts(buff);
// 		puts(key_buff);
// 		puts(val_buff);
// 	}
// 	get_line(fh_open, buff);
// 	if (!get_key(key_buff, buff))
// 		puts("Error\n");
// 	else
// 	{
// 		get_val(val_buff, buff);
// 		puts(buff);
// 		puts(key_buff);
// 		puts(val_buff);
// 	}
// 	get_line(fh_open, buff);
// 	if (!get_key(key_buff, buff))
// 		puts("Error\n");
// 	else
// 	{
// 		get_val(val_buff, buff);
// 		puts(buff);
// 		puts(key_buff);
// 		puts(val_buff);
// 	}
// 	get_line(fh_open, buff);
// 	if (!get_key(key_buff, buff))
// 		puts("Error\n");
// 	else
// 	{
// 		get_val(val_buff, buff);
// 		puts(buff);
// 		puts(key_buff);
// 		puts(val_buff);
// 	}
// 	get_line(fh_open, buff);
// 	if (!get_key(key_buff, buff))
// 		puts("Error\n");
// 	else
// 	{
// 		get_val(val_buff, buff);
// 		puts(buff);
// 		puts(key_buff);
// 		puts(val_buff);
// 	}
// 	get_line(fh_open, buff);
// 	if (!get_key(key_buff, buff))
// 		puts("Error\n");
// 	else
// 	{
// 		get_val(val_buff, buff);
// 		puts(buff);
// 		puts(key_buff);
// 		puts(val_buff);
// 	}
// 	free(buff);
// 	free(val_buff);
// 	free(key_buff);
// 	close(fh_open);
// }
