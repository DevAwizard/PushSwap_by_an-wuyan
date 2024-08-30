/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:20:28 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/25 22:20:56 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	sort_three(t_stack *stack)
{
	int	val1;
	int	val2;
	int	val3;

	val1 = stack->top->value;
	val2 = stack->top->next->value;
	val3 = stack->top->next->next->value;
	if (val1 > val2 && val2 > val3)
	{
		sa(stack);
		rra(stack);
	}
	else if (val1 > val2 && val2 < val3 && val1 > val3)
		ra(stack);
	else if (val1 > val3 && val2 < val3)
		ra(stack);
	else if (val1 < val2 && val2 > val3 && val1 > val3)
		rra(stack);
	else if (val1 < val2 && val2 > val3 && val1 < val3)
	{
		sa(stack);
		ra(stack);
	}
	else if (val1 > val2 && val2 < val3 && val1 < val3)
		sa(stack);
}

void	sort_four(t_stack *a, t_stack *b)
{
	t_node	*min;

	min = find_min(a, INT_MIN);
	while (a->top != min)
	{
		if (min->direction == 1)
			ra(a);
		else
			rra(a);
	}
	pb(b, a);
	sort_three(a);
	pa(a, b);
}

static void	move_min_to_top(t_stack *a, t_node *min)
{
	while (a->top != min)
	{
		if (min->direction == 1)
			ra(a);
		else
			rra(a);
	}
}

void	sort_five(t_stack *a, t_stack *b)
{
	t_node	*min1;
	t_node	*min2;

	min1 = find_min(a, INT_MIN);
	move_min_to_top(a, min1);
	pb(b, a);
	min2 = find_min(a, INT_MIN);
	move_min_to_top(a, min2);
	pb(b, a);
	sort_three(a);
	if (b->top->value < b->top->next->value)
		sb(b);
	pa(a, b);
	pa(a, b);
}
