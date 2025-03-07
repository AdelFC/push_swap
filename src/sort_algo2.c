/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:47:04 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/07 16:18:01 by afodil-c         ###   ########.fr       */
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

void	ft_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;
	int		cost;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		cost = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
		if (cost < cheapest)
		{
			cheapest = cost;
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	ft_execute(stack_a, stack_b, cost_a, cost_b);
}

void	ft_rotate_to_min(t_stack **stack_a)
{
	int	min_p;
	int	size;

	if (!stack_a || !*stack_a)
		return ;
	size = ft_stacksize(*stack_a);
	min_p = ft_min_position(stack_a);
	if (min_p > size / 2)
	{
		while (min_p < size)
		{
			do_reverse_rotate(stack_a, 'a');
			min_p++;
		}
	}
	else
	{
		while (min_p > 0)
		{
			do_rotate(stack_a, 'a');
			min_p--;
		}
	}
}
