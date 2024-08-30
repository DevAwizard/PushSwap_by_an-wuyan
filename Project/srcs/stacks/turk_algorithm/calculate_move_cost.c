/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_move_cost.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:51:42 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/27 11:03:30 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	calculate_cost_for_node(t_node *n_a, int sz_a, int sz_b)
{
	if (n_a->direction == 1 && n_a->target->direction == -1)
		n_a->cost = n_a->index + (sz_b - n_a->target->index);
	else if (n_a->direction == 1 && n_a->target->direction == 1)
	{
		if (n_a->index >= n_a->target->index)
			n_a->cost = n_a->index;
		else
			n_a->cost = n_a->target->index;
	}
	else if (n_a->direction == -1 && n_a->target->direction == 1)
		n_a->cost = n_a->target->index + (sz_a - n_a->index);
	else if (n_a->direction == -1 && n_a->target->direction == -1)
	{
		if ((sz_a - n_a->index) >= (sz_b - n_a->target->index))
			n_a->cost = (sz_a - n_a->index);
		else
			n_a->cost = (sz_b - n_a->target->index);
	}
}

void	calculate_move_costs(t_stack *stk_a, t_stack *stk_b)
{
	t_node	*n_a;
	int		sz_a;
	int		sz_b;

	if (!stk_a || !stk_b)
		return ;
	n_a = stk_a->top;
	sz_a = ft_stack_size(stk_a);
	sz_b = ft_stack_size(stk_b);
	while (n_a)
	{
		if (!n_a->target)
		{
			n_a = n_a->next;
			continue ;
		}
		calculate_cost_for_node(n_a, sz_a, sz_b);
		n_a = n_a->next;
	}
}
