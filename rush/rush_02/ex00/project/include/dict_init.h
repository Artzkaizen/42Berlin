/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_init.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:42:36 by alneuman          #+#    #+#             */
/*   Updated: 2024/09/15 23:41:25 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_INIT_H
# define DICT_INIT_H

typedef struct s_dict
{
	char	**keys_100;
	char	**vals_100;
	char	**keys_pow_1000;
	char	**vals_pow_1000;
	int		max_pow_1000;
	int		is_default;
}	*t_dict;
t_dict	dict_create(void);
t_dict	dict_create_default(void);
void	dict_destroy(t_dict dict);
char	*dict_lookup_100_str(t_dict dict, char *key);
char	*dict_lookup_100_int(t_dict dict, int number);
char	*dict_lookup_pow_1000(t_dict dict, int pow_1000);

#endif //DICT_INIT_H
