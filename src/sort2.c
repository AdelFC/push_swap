/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:05:33 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/06 16:14:14 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack **stack)
{
    t_stack *tmp;

    if (!stack || !(*stack))
        return (1);
    tmp = *stack;
    while (tmp->next)
    {
        if (tmp->value > tmp->next->value)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int ft_stack_min_position(t_stack *stack)
{
    t_stack *tmp;
    int     min;
    int     pos;
    int     i;

    if (!stack)
        return (-1);
    tmp = stack;
    min = tmp->value;
    pos = 0;
    i = 0;
    while (tmp)
    {
        if (tmp->value < min)
        {
            min = tmp->value;
            pos = i;
        }
        tmp = tmp->next;
        i++;
    }
    return (pos);
}

void ft_min_to_top(t_stack **stack, char type)
{
    int min_pos;
    int size;

    if (!stack || !(*stack))
        return;
    size = ft_stacksize(*stack);
    min_pos = ft_stack_min_position(*stack);
    if (min_pos == -1)
        return;
    if (min_pos <= size / 2)
    {
        while (min_pos--)
            do_rotate(stack, type);
    }
    else
    {
        while (size-- > min_pos)
            do_reverse_rotate(stack, type);
    }
}
