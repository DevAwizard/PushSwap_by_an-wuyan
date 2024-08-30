/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anwu-yan <anwu-yan@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:13:19 by anwu-yan          #+#    #+#             */
/*   Updated: 2024/08/30 14:19:05 by anwu-yan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../srcs/libft/libft.h"

# define MAX_DIGITS 10
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define ATOI_ERROR -999999999L
# define FAILURE 999999998L

typedef struct s_node
{
	int				value;
	int				direction;
	struct s_node	*next;
	int				cost;
	struct s_node	*target;
	int				index;
	int				cheap;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

typedef struct s_ord_stat
{
	int		srt;
	int		desc;
}	t_ord_stat;

// Check char digit before converting
int		validate_multiple_arguments(int argc, char **argv);
int		is_sign(char c);
int		is_valid_char(char *string, int index);
int		check_quoted_strings(char *string);
int		is_validargv(char *string, int index);
int		valid_argument(char *string);
int		is_too_long(char *string, int index, int significant_digits);

// Parse validation
int		process_single_argument(char *string, t_stack *stack);
int		process_multiple_arguments(char **array, int count, t_stack *stack);
int		ft_atoi_long(char *str, int i);
int		check_duplicates_char(char **argv, int is_split);
void	process_input(t_stack *stack, int value);
void	update_sort_order(long num, long prev_num, int *srt, int *desc);
int		check_stack_duplicates(t_stack *stack, long num);
int		proc_nbr(char **arr, int cnt, t_stack *stk, t_ord_stat *stat);
int		finalize_processing(int sort, int descend);

// Turk Algorithm
int		is_stack_sorted(t_stack *stack);
t_node	*find_max(t_stack *stack, long max_nbr);
t_node	*find_min(t_stack *stack, long min_nbr);
void	sort_bigger(t_stack *a, t_stack *b);
void	push_swap(t_stack *a, t_stack *b);
int		ft_stack_size(t_stack *stack);

// Sort stack
void	sort_stack(t_stack *a, t_stack *b);
void	sort_three(t_stack *stack);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);

// Stacks operations
int		swap_stack(t_node **lst);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
int		push_stack(t_node **dst, t_node **src);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
int		rotate_stack(t_node **lst);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
int		reverse_stack(t_node **lst);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// Set stacks
void	init_sort_data(t_stack *a, t_stack *b);
void	assign_targets(t_stack *a, t_stack *b);
void	set_index_direction(t_stack *stack);
void	calculate_move_costs(t_stack *a, t_stack *b);
void	mark_min_cost(t_stack *a);

// Calculate move cost
void	calculate_move_costs(t_stack *stk_a, t_stack *stk_b);
void	calculate_cost_for_node(t_node *n_a, int sz_a, int sz_b);

// Sorting loop
void	sort_elements(t_stack *a, t_stack *b);
t_node	*min_cost(t_stack *lst);
void	rotate_same(t_stack *a, t_stack *b, t_node *cheapest);
void	rotate_up(int index_a, int index_b, t_stack *a, t_stack *b);
void	rotate_down(int aux_a, int aux_b, t_stack *a, t_stack *b);
void	rotate_diff(t_stack *a, t_stack *b, t_node *cheap);

// Back to a loop
void	move_back_to_a(t_stack *a, t_stack *b);

// Check top
void	align_min_to_top(t_stack *a);

// Free memory
void	free_array(char **array);
void	free_stack(t_stack *stack);

// Error message arguments
int		ft_error_single_argument(void);
int		ft_error_multiple_arguments(void);
void	ft_error_split_argument(char **array);
int		ft_error_duplicates_int(t_stack *a);
int		ft_error_duplicates_char(void);
void	ft_error_over_under_flow_multi(t_stack *a);
void	ft_error_over_under_flow_single(char **split_argv, t_stack *a);

#endif
