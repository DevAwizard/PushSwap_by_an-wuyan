/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:32:30 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/28 16:10:49 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	count_elements(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

int	check_duplicates_char(char **argv, int is_split)
{
	int		i;
	int		j;
	long	num_i;
	long	num_j;

	i = 0;
	while (argv[i] != NULL)
	{
		num_i = ft_atoi_long(argv[i], 0);
		j = i + 1;
		while (argv[j] != NULL)
		{
			num_j = ft_atoi_long(argv[j], 0);
			if (num_i == num_j)
			{
				if (is_split)
					free_array(argv);
				ft_error_duplicates_char();
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	process_single_argument(char *string, t_stack *stack)
{
	char	**split_argv;
	int		count;
	int		result;
	int		i;
	long	num;

	result = 0;
	split_argv = ft_split(string, ' ');
	if (!split_argv)
		return (ft_error_split_argument(split_argv), 0);
	if (!check_duplicates_char(split_argv, 1))
		return (0);
	count = count_elements(split_argv);
	i = 0;
	while (i < count)
	{
		num = ft_atoi_long(split_argv[i], 0);
		if (num == ATOI_ERROR)
			ft_error_over_under_flow_single(split_argv, stack);
		i++;
	}
	result = process_multiple_arguments(split_argv, count, stack);
	free_array(split_argv);
	return (result);
}

int	process_multiple_arguments(char **array, int count, t_stack *stack)
{
	t_ord_stat	sort_info;

	sort_info.srt = 1;
	sort_info.desc = 1;
	if (!proc_nbr(array, count, stack, &sort_info))
		return (0);
	return (finalize_processing(sort_info.srt, sort_info.desc));
}
