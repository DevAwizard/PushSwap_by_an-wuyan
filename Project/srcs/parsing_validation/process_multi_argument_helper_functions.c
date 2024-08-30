/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_multi_argument_helper_functions.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:30:45 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/28 16:08:40 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	update_sort_order(long num, long prev_num, int *srt, int *desc)
{
	if (num < prev_num)
		*srt = 0;
	if (num > prev_num)
		*desc = 0;
}

int	check_stack_duplicates(t_stack *stack, long num)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == num)
			return (0);
		current = current->next;
	}
	return (1);
}

int	proc_nbr(char **arr, int cnt, t_stack *stk, t_ord_stat *stat)
{
	int		i;
	long	prev_num;
	long	num;

	i = 0;
	prev_num = 0;
	num = 0;
	while (i < cnt)
	{
		num = ft_atoi_long(arr[i], 0);
		if (num == ATOI_ERROR)
			ft_error_over_under_flow_multi(stk);
		if (i > 0)
			update_sort_order(num, prev_num, &(stat->srt), &(stat->desc));
		if (!check_stack_duplicates(stk, num))
			return (ft_error_duplicates_int(stk), 0);
		process_input(stk, (int)num);
		prev_num = num;
		i++;
	}
	return (1);
}

int	finalize_processing(int sort, int descend)
{
	if (descend && !sort)
		sort = 0;
	if (!sort)
		return (0);
	return (1);
}
