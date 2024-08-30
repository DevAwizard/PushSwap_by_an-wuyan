/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:16:05 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/30 14:20:45 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	initialize_stacks(t_stack *a, t_stack *b)
{
	a->top = NULL;
	b->top = NULL;
}

static int	handle_single_argument(char *arg, t_stack *a)
{
	if (!valid_argument(arg))
	{
		ft_error_single_argument();
		return (0);
	}
	if (!process_single_argument(arg, a))
	{
		return (0);
	}
	return (1);
}

static int	handle_multiple_arguments(int argc, char **argv, t_stack *a)
{
	if (!validate_multiple_arguments(argc, argv))
	{
		ft_error_multiple_arguments();
		return (0);
	}
	if (!process_multiple_arguments(argv + 1, argc - 1, a))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	initialize_stacks(&a, &b);
	if (argc == 1)
		return (1);
	else if (argc == 2)
	{
		if (!handle_single_argument(argv[1], &a))
			push_swap(&a, &b);
	}
	else if (argc > 2)
	{
		if (!handle_multiple_arguments(argc, argv, &a))
			push_swap(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
