/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:18:11 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/08 00:54:35 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_except_three(t_stack **stack_a, t_stack **stack_b)
{
	int	count;
	int	size;
	int	i;

	if (!stack_a || !(*stack_a) || !stack_b)
		return ;
	size = ft_stacksize(*stack_a);
	if (size <= 3)
		return ;
	i = 0;
	count = 0;
	while (size > 6 && i < size && count < size / 2)
	{
		if ((*stack_a)->index == -1)
			return ;
		if ((*stack_a)->index <= size / 2)
		{
			do_push(stack_a, stack_b, 'b');
			count++;
		}
		else
			do_rotate(stack_a, 'a');
		i++;
	}
	while (ft_stacksize(*stack_a) > 3)
	{
		do_push(stack_a, stack_b, 'b');
		count++;
	}
}

void	ft_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

int	ft_target(t_stack **stack_a, int index_b)
{
	t_stack	*tmp;
	int		target_holder;
	int		target_p;

	if (!stack_a || !*stack_a)
		return (0);
	tmp = *stack_a;
	target_holder = INT_MAX;
	target_p = 0;
	while (tmp)
	{
		if (tmp->index == -1)
			return (-1);
		if (tmp->position == -1)
			tmp->position = 0;
		if (tmp->index > index_b && tmp->index < target_holder)
		{
			target_holder = tmp->index;
			target_p = tmp->position;
		}
		tmp = tmp->next;
	}
	if (target_holder != INT_MAX)
		return (target_p);
	return (ft_min_position(stack_a));
}

void	ft_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	ft_position(stack_a);
	ft_position(stack_b);
	tmp_b = *stack_b;
	while (tmp_b)
	{
		tmp_b->target = ft_target(stack_a, tmp_b->index);
		tmp_b = tmp_b->next;
	}
}

int	ft_min_position(t_stack **stack)
{
	t_stack	*tmp;
	int		min_i;
	int		min_p;

	if (!stack || !*stack)
		return (-1);
	ft_position(stack);
	tmp = *stack;
	min_i = INT_MAX;
	min_p = 0;
	while (tmp)
	{
		if (tmp->index < min_i)
		{
			min_i = tmp->index;
			min_p = tmp->position;
		}
		tmp = tmp->next;
	}
	return (min_p);
}
