/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:22:49 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/13 22:03:13 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	validate_multiple_arguments(int argc, char **argv)
{
	int	index;
	int	j;

	index = 1;
	while (index < argc)
	{
		j = 0;
		if (!check_quoted_strings(argv[index]))
			return (0);
		while (argv[index][j] != '\0')
		{
			if (argv[index][j] == ' ')
				return (0);
			if (!valid_argument(argv[index]))
				return (0);
			j++;
		}
		index++;
	}
	return (1);
}
