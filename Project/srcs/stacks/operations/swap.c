/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 20:53:39 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/25 21:29:06 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	swap_stack(t_node **stack)
{
	t_node	*temp2;
	t_node	*temp1;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	temp2 = (*stack)->next;
	temp1 = *stack;
	temp1->next = temp2->next;
	temp2->next = temp1;
	*stack = temp2;
	return (1);
}

// Swap the first two elements of stack a
void	sa(t_stack *a)
{
	if (swap_stack(&(a->top)) == 1)
		ft_printf("sa\n");
}

// Swap the first two elements of stack b
void	sb(t_stack *b)
{
	if (swap_stack(&(b->top)) == 1)
		ft_printf("sb\n");
}

// Swap the first two elements of both stacks a and b simultaneously
void	ss(t_stack *a, t_stack *b)
{
	int	a_result;
	int	b_result;

	a_result = swap_stack(&(a->top));
	b_result = swap_stack(&(b->top));
	if (a_result == 1 || b_result == 1)
		ft_printf("ss\n");
}
