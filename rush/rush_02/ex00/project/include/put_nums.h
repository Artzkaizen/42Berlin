/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nums.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:08:56 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/15 22:06:05 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict_init.h"
#include "utils.h"

void	print_num_in_words(char *n_rev, t_dict dict);
void	ft_putstr_comb(char *sep, char *str, char *syntax);
int		put_nbr_999(char *str, t_dict dict, int *first_word);
int		put_nbr_999_helper(char *str, t_dict dict, int *first_word);
void	put_nbr_natl(char *n_rev, int power, t_dict dict, int *first_group);
void	put_nbr_natl_helper(char *n_rev, int power, t_dict dict, 
			int *first_group);