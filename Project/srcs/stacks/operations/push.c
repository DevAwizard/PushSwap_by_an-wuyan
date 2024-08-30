/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 20:53:31 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/25 21:25:16 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	push_stack(t_node **dst, t_node **src)
{
	t_node	*temp;

	if (*src == NULL)
		return (0);
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
	return (1);
}

void	pa(t_stack *a, t_stack *b)
{
	if (push_stack(&(a->top), &(b->top)) == 1)
		ft_printf("pa\n");
}

void	pb(t_stack *b, t_stack *a)
{
	if (push_stack(&(b->top), &(a->top)) == 1)
		ft_printf("pb\n");
}
