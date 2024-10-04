/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:56:28 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/18 10:04:35 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		lenght;
	char	*dest;

	lenght = 0;
	while (s[lenght])
		lenght++;
	dest = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!dest)
		return (NULL);
	while (lenght >= 0)
	{
		dest[lenght] = s[lenght];
		lenght--;
	}
	return (dest);
}
