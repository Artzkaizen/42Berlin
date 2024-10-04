/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:41:58 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/04 20:29:20 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (s1[index] == s2[index] && s1[index] && s2[index] && index < n)
		index++;
	if (index == n)
		return (0);
	else
		return (s1[index] - s2[index]);
}
