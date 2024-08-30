/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:40:02 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/28 16:08:13 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_error_duplicates_char(void)
{
	write(2, "Error\n", 6);
	write(2, "Duplicate number detected.\n", 27);
	exit(FAILURE);
}

int	ft_error_duplicates_int(t_stack *a)
{
	write(2, "Error\n", 6);
	write(2, "Duplicate number detected.\n", 27);
	free_stack(a);
	exit(FAILURE);
}

void	ft_error_split_argument(char **array)
{
	write(2, "Error\n", 6);
	write(2, "Failed to split the argument string.\n", 36);
	free_array(array);
	exit(EXIT_FAILURE);
}

void	ft_error_over_under_flow_single(char **split_argv, t_stack *a)
{
	if (split_argv != NULL)
		free_array(split_argv);
	write(2, "Error\n", 6);
	write(2, "Integer overflow/underflow detected.\n", 37);
	if (a != NULL)
		free_stack(a);
	exit(FAILURE);
}

void	ft_error_over_under_flow_multi(t_stack *a)
{
	write(2, "Error\n", 6);
	write(2, "Integer overflow/underflow detected.\n", 37);
	if (a != NULL)
		free_stack(a);
	exit(FAILURE);
}
