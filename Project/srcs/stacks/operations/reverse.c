/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 20:53:07 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/25 21:26:28 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	reverse_stack(t_node **stack)
{
	t_node	*last;
	t_node	*second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	last = *stack;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rra(t_stack *a)
{
	if (reverse_stack(&(a->top)) == 1)
		ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	if (reverse_stack(&(b->top)) == 1)
		ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	int	a_result;
	int	b_result;

	a_result = reverse_stack(&(a->top));
	b_result = reverse_stack(&(b->top));
	if (a_result == 1 || b_result == 1)
		ft_printf("rrr\n");
}
