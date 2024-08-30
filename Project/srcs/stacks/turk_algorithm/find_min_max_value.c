/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:09:54 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/27 11:01:16 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

t_node	*find_min(t_stack *stack, long min_nbr)
{
	long	min;
	t_node	*min_node;
	t_node	*current;

	min_node = NULL;
	min = INT_MAX;
	current = stack->top;
	while (current)
	{
		if (current->value == INT_MIN)
			return (current);
		if (current->value < min && current->value > min_nbr)
		{
			min = current->value;
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

t_node	*find_max(t_stack *stack, long max_nbr)
{
	long	max;
	t_node	*max_node;
	t_node	*current;

	max = INT_MIN;
	max_node = NULL;
	current = stack->top;
	while (current)
	{
		if (current->value == INT_MAX)
			return (current);
		if (current->value > max && current->value < max_nbr)
		{
			max = current->value;
			max_node = current;
		}
		current = current->next;
	}
	return (max_node);
}
