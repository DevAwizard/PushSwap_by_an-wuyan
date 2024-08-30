/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:36:26 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/27 10:51:33 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

t_node	*min_cost(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->cheap == 1)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	rotate_same(t_stack *a, t_stack *b, t_node *cheapest)
{
	int	aux_a;
	int	aux_b;
	int	index_a;
	int	index_b;

	index_a = cheapest->index;
	index_b = cheapest->target->index;
	aux_a = ft_stack_size(a) - index_a;
	aux_b = ft_stack_size(b) - index_b;
	if (cheapest->direction == 1)
		rotate_up(index_a, index_b, a, b);
	else if (cheapest->direction == -1)
		rotate_down(aux_a, aux_b, a, b);
}

void	rotate_up(int index_a, int index_b, t_stack *a, t_stack *b)
{
	if (index_a >= index_b)
	{
		while (index_b-- > 0 && index_a-- > 0)
			rr(a, b);
		while (index_a-- > 0)
			ra(a);
	}
	else if (index_a < index_b)
	{
		while (index_a-- > 0 && index_b-- > 0)
			rr(a, b);
		while (index_b-- > 0)
			rb(b);
	}
	pb(b, a);
}

void	rotate_down(int aux_a, int aux_b, t_stack *a, t_stack *b)
{
	if (aux_a >= aux_b)
	{
		while (aux_b-- > 0 && aux_a-- > 0)
			rrr(a, b);
		while (aux_a-- > 0)
			rra(a);
	}
	else if (aux_a < aux_b)
	{
		while (aux_a-- > 0 && aux_b-- > 0)
			rrr(a, b);
		while (aux_b-- > 0)
			rrb(b);
	}
	pb(b, a);
}

void	rotate_diff(t_stack *a, t_stack *b, t_node *cheap)
{
	int	aux_a;
	int	aux_b;
	int	index_a;
	int	index_b;

	index_a = cheap->index;
	index_b = cheap->target->index;
	aux_a = ft_stack_size(a) - index_a;
	aux_b = ft_stack_size(b) - index_b;
	if (cheap->direction == 1 && cheap->target->direction == -1)
	{
		while (index_a-- > 0)
			ra(a);
		while (aux_b-- > 0)
			rrb(b);
	}
	else if (cheap->direction == -1 && cheap->target->direction == 1)
	{
		while (aux_a-- > 0)
			rra(a);
		while (index_b-- > 0)
			rb(b);
	}
	pb(b, a);
}
