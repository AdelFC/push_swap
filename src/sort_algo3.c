/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:29:04 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/07 16:14:39 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_reverse_rotate_both_cost(t_stack **stack_a, t_stack **stack_b,
		int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		do_reverse_rotate_both(stack_a, stack_b);
	}
}

void	do_rotate_both_cost(t_stack **stack_a, t_stack **stack_b, int *cost_a,
		int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		do_rotate_both(stack_a, stack_b);
	}
}

void	do_rotate_cost(t_stack **stack, int *cost, char type)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			do_rotate(stack, type);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			do_reverse_rotate(stack, type);
			(*cost)++;
		}
	}
}

void	ft_execute(t_stack **stack_a, t_stack **stack_b, int cost_a,
		int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_reverse_rotate_both_cost(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rotate_both_cost(stack_a, stack_b, &cost_a, &cost_b);
	do_rotate_cost(stack_a, &cost_a, 'a');
	do_rotate_cost(stack_b, &cost_b, 'b');
	do_push(stack_a, stack_b, 'a');
}
