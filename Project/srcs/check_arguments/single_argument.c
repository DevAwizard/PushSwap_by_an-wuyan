/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_argument.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:16:49 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/30 14:16:01 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_validargv(char *string, int index)
{
	while (string[index] != '\0')
	{
		if (string[index] == '+' || string[index] == '-')
		{
			index++;
			if (!ft_isdigit(string[index]))
				return (0);
		}
		while (ft_isdigit(string[index]))
			index++;
		if (string[index] != '\0' && string[index] != ' ')
			return (0);
		while (string[index] == ' ')
			index++;
		if (string[index] == '\0')
			break ;
	}
	return (1);
}

int	valid_argument(char *string)
{
	while (*string == ' ')
		string++;
	if (*string == '\0')
		return (0);
	if (is_too_long(string, 0, 0))
		return (0);
	if (!is_validargv(string, 0))
		return (0);
	return (1);
}
