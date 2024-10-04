/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nums.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 21:08:35 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/15 23:12:50 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict_init.h"
#include "utils.h"
#include "put_nums.h"

void	put_nbr_natl_helper(char *n_rev, int power, t_dict dict,
		int *first_group)
{
	int	is_zero;
	int	first_word;

	first_word = 1;
	is_zero = put_nbr_999(n_rev, dict, &first_word);
	if (!is_zero)
	{
		if (power > 0)
		{
			ft_putstr_comb(" ", dict_lookup_pow_1000(dict, power), "");
		}
		*first_group = 0;
	}
}

void	print_num_in_words(char *n_rev, t_dict dict)
{
	int	first_word;
	int	first_group;

	first_word = 1;
	first_group = 1;
	if (ft_strlen(n_rev) == 1 && *n_rev == '0')
		ft_putstr(dict_lookup_100_int(dict, 100));
	else if (ft_strlen(n_rev) <= 3)
		put_nbr_999(n_rev, dict, &first_word);
	else
		put_nbr_natl(n_rev, 0, dict, &first_group);
}

void	put_nbr_natl(char *n_rev, int power, t_dict dict, int *first_group)
{
	if (!n_rev[0])
		return ;
	if (!n_rev[2] || !n_rev[1])
	{
		put_nbr_natl_helper(n_rev, power, dict, first_group);
		return ;
	}
	put_nbr_natl(n_rev + 3, power + 1, dict, first_group);
	if (!*first_group)
		ft_putstr(", ");
	put_nbr_natl_helper(n_rev, power, dict, first_group);
}

int	put_nbr_999_helper(char *str, t_dict dict, int *first_word)
{
	if (str[1] && str[1] != '0')
	{
		if (!*first_word)
			ft_putstr(" ");
		if (str[1] == '1' && str[0] != '0')
			ft_putstr(dict_lookup_100_int(dict, (str[0] - '0') + 10));
		else
		{
			ft_putstr(dict_lookup_100_int(dict, (str[1] - '0') * 10));
			if (str[0] != '0')
				ft_putstr("-");
		}
	}
	if (str[0] && str[1] != '1' && (str[0] - '0'))
		ft_putstr(dict_lookup_100_int(dict, str[0] - '0'));
	*first_word = 0;
	return (0);
}

int	put_nbr_999(char *str, t_dict dict, int *first_word)
{
	if (str[0] == '0' && str[1] == '0' && str[2] == '0')
		return (1);
	if (str[2] && str[2] != '0')
	{
		if (!*first_word)
			ft_putstr(" ");
		ft_putstr(dict_lookup_100_int(dict, (str[2] - 48)));
		ft_putstr_comb(" ", dict_lookup_100_int(dict, 100), " and ");
	}
	return (put_nbr_999_helper(str, dict, first_word));
}
