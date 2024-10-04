/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:44:59 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/04 20:28:35 by chuezeri         ###   ########.fr       */
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
