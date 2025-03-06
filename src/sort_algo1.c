/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:18:11 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/06 21:18:29 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_except_three(t_stack **stack_a, t_stack **stack_b)
{
    int count;
    int size;
    int i;

    if (!stack_a || !(*stack_a) || !stack_b)
        return;
    count = 0;
    size = ft_stacksize(*stack_a);
    i = 0;
    while (size > 6 && i < size && count < size / 2)
    {
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

void	assign_position(t_stack **stack)
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

int	find_target(t_stack **stack_a, int b_index)
{
	t_stack	*tmp;
	int		closest;
	int		pos_target;
	int		min_index;
	int		min_pos;

	if (!stack_a || !*stack_a)
		return (0);

	tmp = *stack_a;
	closest = INT_MAX;
	min_index = INT_MAX;
	pos_target = 0;
	min_pos = 0;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < closest)
		{
			closest = tmp->index;
			pos_target = tmp->position;
		}
		if (tmp->index < min_index)
		{
			min_index = tmp->index;
			min_pos = tmp->position;
		}
		tmp = tmp->next;
	}
	if (closest != INT_MAX)
		return pos_target;
	else
		return min_pos;
}


void	assign_target_positions(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	assign_position(stack_a);
	assign_position(stack_b);
	tmp_b = *stack_b;
	while (tmp_b)
	{
		tmp_b->target = find_target(stack_a, tmp_b->index);
		tmp_b = tmp_b->next;
	}
}


int	find_lowest_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	if (!stack || !*stack)
		return (-1);
	assign_position(stack);
	tmp = *stack;
	lowest_index = INT_MAX;
	lowest_pos = 0;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->position;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}
