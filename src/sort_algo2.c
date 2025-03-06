/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:47:04 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/06 20:51:55 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;
	int		mid_a;
	int		mid_b;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	size_a = ft_stacksize(*stack_a);
	size_b = ft_stacksize(*stack_b);
	mid_a = size_a / 2;
	mid_b = size_b / 2;
	tmp_b = *stack_b;
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->position;
		if (tmp_b->position > mid_b)
			tmp_b->cost_b = tmp_b->position - size_b;
		tmp_b->cost_a = tmp_b->target;
		if (tmp_b->target > mid_a)
			tmp_b->cost_a = tmp_b->target - size_a;
		tmp_b = tmp_b->next;
	}
}

void	execute_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;
	int		move_cost;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		move_cost = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
		if (move_cost < cheapest)
		{
			cheapest = move_cost;
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	execute_move(stack_a, stack_b, cost_a, cost_b);
}

void	ft_rotate_to_min(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	if (!stack_a || !*stack_a)
		return ;

	stack_size = ft_stacksize(*stack_a);
	lowest_pos = find_lowest_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
            do_reverse_rotate(stack_a, 'a');
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_rotate(stack_a, 'a');
			lowest_pos--;
		}
	}
}
