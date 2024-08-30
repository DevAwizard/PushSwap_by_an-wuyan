/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:57:24 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/28 16:18:09 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_error_single_argument(void)
{
	write(2, "Error\n", 6);
	write(2, "Invalid single input detected.\n", 32);
	exit(EXIT_FAILURE);
}

int	ft_error_multiple_arguments(void)
{
	write(2, "Error\n", 6);
	write(2, "Invalid multiple input detected.\n", 34);
	exit(EXIT_FAILURE);
}
