/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:13:33 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/09 17:03:46 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	length;
	unsigned int	dest_length;
	unsigned int	src_length;

	count = 0;
	length = ft_strlen(dest);
	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	if (size <= dest_length)
		return (size + src_length);
	while (src[count] && count < size - dest_length - 1)
	{
		dest[length + count] = src[count];
		count++;
	}
	dest[length + count] = '\0';
	return (dest_length + src_length);
}
dest = "hello\0"
ft_strlcat(dest, src, 4);