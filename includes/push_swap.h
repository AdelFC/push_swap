/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:27:38 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/07 16:17:16 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/ftprintf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../utils/stack_utils.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	ft_print_error(int code);

int		ft_isnum(char *str);
int		ft_check_double(char **argv);
int		ft_check_args(int argc, char **argv);
void	ft_free_split(char **split);

void	ft_push(t_stack **src, t_stack **dest);
void	do_push(t_stack **stack_a, t_stack **stack_b, char type);

void	ft_swap(t_stack **stack);
void	do_swap(t_stack **stack, char type);
void	do_swap_both(t_stack **stack_a, t_stack **stack_b);

void	ft_rotate(t_stack **stack);
void	do_rotate(t_stack **stack, char type);
void	do_rotate_both(t_stack **stack_a, t_stack **stack_b);

void	ft_reverse_rotate(t_stack **stack);
void	do_reverse_rotate(t_stack **stack, char type);
void	do_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

t_stack	*ft_initialize_stack(int argc, char **argv, t_stack *stack_a);

int		is_sorted(t_stack **stack);
void	ft_index(t_stack *stack_a, int stack_size);

int		ft_stack_min_position(t_stack *stack);
void	ft_min_to_top(t_stack **stack, char type);

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size);
void	ft_sort_two(t_stack **stack);
void	ft_sort_three(t_stack **stack);
void	ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);

void	ft_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_except_three(t_stack **stack_a, t_stack **stack_b);
void	ft_position(t_stack **stack);
int		ft_target(t_stack **stack_a, int index_b);
void	ft_target_position(t_stack **stack_a, t_stack **stack_b);
void	ft_cost(t_stack **stack_a, t_stack **stack_b);

void	do_reverse_rotate_both_cost(t_stack **stack_a, t_stack **stack_b,
			int *cost_a, int *cost_b);
void	do_rotate_both_cost(t_stack **stack_a, t_stack **stack_b, int *cost_a,
			int *cost_b);
void	do_rotate_cost(t_stack **stack, int *cost, char type);
void	ft_execute(t_stack **stack_a, t_stack **stack_b, int cost_a,
			int cost_b);
void	ft_cheapest(t_stack **stack_a, t_stack **stack_b);

int		ft_min_position(t_stack **stack);
void	ft_rotate_to_min(t_stack **stack_a);

int		main(int argc, char **argv);

#endif
