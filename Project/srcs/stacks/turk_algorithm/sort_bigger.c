/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 19:56:27 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/26 23:01:03 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	init_sort_data(t_stack *a, t_stack *b)
{
	if (!a || !b || !a->top || !b->top)
		return ;
	set_index_direction(a);
	set_index_direction(b);
	assign_targets(a, b);
	calculate_move_costs(a, b);
	mark_min_cost(a);
}

void	sort_bigger(t_stack *a, t_stack *b)
{
	if (!a || !a->top || !a->top->next)
		return ;
	pb(b, a);
	pb(b, a);
	if (b->top && b->top->next && b->top->value < b->top->next->value)
		sb(b);
	init_sort_data(a, b);
	sort_elements(a, b);
	move_back_to_a(a, b);
	align_min_to_top(a);
}
