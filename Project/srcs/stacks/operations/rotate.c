/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 20:53:36 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/25 21:28:08 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	rotate_stack(t_node **stack)
{
	t_node	*temp;
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return (0);
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = temp;
	return (1);
}

// Rotate stack a upwards (first element becomes last)
void	ra(t_stack *a)
{
	if (rotate_stack(&(a->top)) == 1)
		ft_printf("ra\n");
}

// Rotate stack b upwards (first element becomes last)
void	rb(t_stack *b)
{
	if (rotate_stack(&(b->top)) == 1)
		ft_printf("rb\n");
}

// Rotate both stacks a and b upwards simultaneously
void	rr(t_stack *a, t_stack *b)
{
	int	a_result;
	int	b_result;

	a_result = rotate_stack(&(a->top));
	b_result = rotate_stack(&(b->top));
	if (a_result == 1 || b_result == 1)
		ft_printf("rr\n");
}
