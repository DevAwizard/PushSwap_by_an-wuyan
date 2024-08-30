/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:18:22 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/25 20:59:46 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	check_quoted_strings(char *string)
{
	if (string[0] == '\0' || string[0] == ' ')
		return (0);
	if ((string[0] == '"' && string[1] == '"') || \
		(string[0] == '"' && string[1] == ' ' && string[2] == '"'))
		return (0);
	if ((string[0] == '"' && string[1] != '\0' && string[1] != ' ') || \
		(string[0] != '\0' && string[1] == '"' && string[2] != ' '))
		return (0);
	return (1);
}

int	is_too_long(char *string, int index, int significant_digits)
{
	if (is_sign(string[index]))
		index++;
	while (string[index] == ' ')
		index++;
	while (string[index] == '0')
		index++;
	while (ft_isdigit(string[index]))
	{
		significant_digits++;
		index++;
	}
	if (significant_digits == 0)
		significant_digits = 1;
	if (significant_digits > MAX_DIGITS)
		return (1);
	return (0);
}
