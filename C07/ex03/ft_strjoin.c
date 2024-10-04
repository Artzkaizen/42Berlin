/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:29:03 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/18 09:43:22 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int	count;
	int	lenght;

	count = 0;
	lenght = ft_strlen(dest);
	while (src[count])
	{
		dest[lenght + count] = src[count];
		count++;
	}
	dest[lenght + count] = '\0';
	return (dest);
}

int	total_strs_len(char **strs, int size)
{
	int	i;
	int	len;

	i = 0;
	len = 1;
	while (i < size)
	{
		len = ft_strlen(strs[i]) + len;
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		strs_len;
	char	*string;

	strs_len = total_strs_len(strs, size) + (ft_strlen(sep) * (size - 1));
	if (size < 1)
		string = (char *)malloc(sizeof(char));
	else
		string = (char *)malloc(sizeof(char) * strs_len);
	if (!string)
		return (NULL);
	string[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(string, strs[i]);
		if (i != size - 1)
			ft_strcat(string, sep);
		i++;
	}
	return (string);
}
// #include <stdio.h>

// int    main(void)
// {
//     char *str[] = {"Hello", "", "", "Chuka", "Bye!"};
// 	char *new_string;

// 	new_string = ft_strjoin(5, str, "-");
//     printf("New string: %s\n", new_string);
// 	free(new_string);
// }