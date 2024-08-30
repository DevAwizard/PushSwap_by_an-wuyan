/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:11:14 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/27 10:59:13 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	move_back_to_a(t_stack *a, t_stack *b)
{
	while (b->top)
		pa(a, b);
}

void	align_min_to_top(t_stack *a)
{
	t_node	*min;

	min = find_min(a, INT_MIN);
	while (a->top->value != min->value)
	{
		if (min->direction == 1)
			ra(a);
		else
			rra(a);
	}
}

void	sort_elements(t_stack *a, t_stack *b)
{
	int		len;
	t_node	*cheapest;

	len = ft_stack_size(a);
	while (len > 0)
	{
		cheapest = min_cost(a);
		if (cheapest != NULL)
		{
			if (cheapest->direction == cheapest->target->direction)
				rotate_same(a, b, cheapest);
			else
				rotate_diff(a, b, cheapest);
		}
		init_sort_data(a, b);
		len = ft_stack_size(a);
	}
}
