/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 10:20:55 by chuezeri          #+#    #+#             */
/*   Updated: 2024/09/19 16:49:46 by chuezeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_valid_base(char *str);
int		ft_atoi_base(char *str, char *base);
void	ft_putnbr_base(int nbr, char *base, char *string, int *i);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		dec;
	char	*string;

	if (!ft_is_valid_base(base_from) || !ft_is_valid_base(base_to)
		|| !nbr || !*nbr)
		return (NULL);
	string = malloc(35);
	if (!string)
		return (NULL);
	i = 0;
	while (i < 35)
		string[i++] = '\0';
	i = 0;
	dec = ft_atoi_base(nbr, base_from);
	ft_putnbr_base(dec, base_to, string, &i);
	if (i == 0)
		return (NULL);
	return (string);
}
#include <stdio.h>

int main(void)
{
	 char *test_cases[][3] = {
		{"", "0123456789", "0123456"},			
		{"123", "0123456789", "01"},			
		{"101", "01", "0123456789"},			 
		{"7F", "0123456789ABCDEF", "01234567"}, 
		{"101", "01", "0123456789ABCDEF"},		 
		{"", "0123456789", "0123456789"},		
		{"123", "", "01"},
		{"123", "0123456789", ""},				
		{"123", "01", "0"},
		{"123", "01", "01"},
		{"123", "0123456789a", "0123456789"},
		{"123", "0123456789", "0123456789!@"}
	};

	for (unsigned long i = 0; i < sizeof(test_cases) 
		/ sizeof(test_cases[0]); i++)
	{
		 char *nbr = test_cases[i][0];
		 char *base_from = test_cases[i][1];
		 char *base_to = test_cases[i][2];

		char *result = ft_convert_base(nbr, base_from, base_to);

		// Print test case details
		printf("Test %lu:\n", i + 1);
		printf("Input number: \"%s\"\n", nbr);
		printf("Base from: \"%s\"\n", base_from);
		printf("Base to: \"%s\"\n", base_to);

		// Print result or error message
		if (result)
		{
			printf("Converted result: \"%s\"\n", result);
			free(result); // Free the result if dynamically allocated
		}
		else
		{
			printf("Conversion result: NULL (error or invalid base)\n");
		}
		printf("---------\n");
	}
	return 0;
}
