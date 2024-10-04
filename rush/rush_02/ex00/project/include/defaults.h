/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaults.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:55:42 by alneuman          #+#    #+#             */
/*   Updated: 2024/09/15 23:25:38 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFAULTS_H
# define DEFAULTS_H

# include <stdlib.h>

# define NUM_KEYS_100 29
# define NUM_KEYS_1000 12

char	*g_def_keys_100[NUM_KEYS_100 + 1] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "30", "40", "50", "60", "70", "80", "90", "100", NULL}; 

char	*g_def_vals_100[NUM_KEYS_100 + 1] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred", NULL}; 

char	*g_def_keys_pow_1000[NUM_KEYS_1000 + 3] = { "", "1000", "1000000", "1000000000", "1000000000000", "1000000000000000", "1000000000000000000", "1000000000000000000000", "1000000000000000000000000", "1000000000000000000000000000", "1000000000000000000000000000000", "1000000000000000000000000000000000", "1000000000000000000000000000000000000", NULL }; 

char	*g_def_vals_pow_1000[NUM_KEYS_1000 + 3] = { "", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion", "septillion", "octillion", "nonillion", "decillion", "undecillion", NULL};

#endif //DEFAULTS_H