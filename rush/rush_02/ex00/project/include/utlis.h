/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:23:41 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/15 16:25:11 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTLIS_H
# define UTLIS_H

# include <unistd.h>

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_putstr_comb(char *sep, char *str, char *syntax);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(char *s1, char *s2);

#endif
