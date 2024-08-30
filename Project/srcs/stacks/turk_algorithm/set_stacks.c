/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 23:51:20 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/27 10:58:51 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static void	set_node_direction(t_node *current, int i, int half, int len)
{
	current->index = i;
	if (i > half)
		current->direction = -1;
	else if (i == half)
	{
		if (len % 2 == 0)
			current->direction = -1;
		else
			current->direction = 1;
	}
	else
		current->direction = 1;
}

void	set_index_direction(t_stack *stack)
{
	int		i;
	int		half;
	int		len;
	t_node	*current;

	len = ft_stack_size(stack);
	half = len / 2;
	i = 0;
	current = stack->top;
	while (current)
	{
		set_node_direction(current, i, half, len);
		i++;
		current = current->next;
	}
}

void	assign_targets(t_stack *a, t_stack *b)
{
	t_node	*current_a;
	t_node	*target_node;

	if (!a || !b || !b->top)
		return ;
	current_a = a->top;
	while (current_a)
	{
		target_node = find_max(b, current_a->value);
		if (target_node == NULL)
		{
			target_node = find_max(b, INT_MAX);
			if (target_node == NULL)
				return ;
		}
		current_a->target = target_node;
		current_a = current_a->next;
	}
}

void	mark_min_cost(t_stack *a)
{
	t_node	*current;
	int		cheapest;
	t_node	*cheapest_node;

	if (!a || !a->top)
		return ;
	current = a->top;
	cheapest = INT_MAX;
	cheapest_node = NULL;
	while (current != NULL)
	{
		if (current->cost == 0)
		{
			current->cheap = 1;
			return ;
		}
		if (current->cost < cheapest)
		{
			cheapest = current->cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	if (cheapest_node != NULL)
		cheapest_node->cheap = 1;
}
