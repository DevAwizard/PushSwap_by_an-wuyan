/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:41:34 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/28 18:45:56 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

static t_node	*new_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->direction = 0;
	node->next = NULL;
	node->cost = 0;
	node->target = NULL;
	node->index = 0;
	node->cheap = 0;
	return (node);
}

static void	push_to_bottom(t_stack *stack, int value)
{
	t_node	*node;
	t_node	*current;

	node = new_node(value);
	if (stack->top == NULL)
		stack->top = node;
	else
	{
		current = stack->top;
		while (current->next != NULL)
			current = current->next;
		current->next = node;
	}
}

void	process_input(t_stack *stack, int value)
{
	push_to_bottom(stack, value);
}
