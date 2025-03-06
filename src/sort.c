/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:03:57 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/06 16:15:27 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_two(t_stack **stack)
{
    if (!stack || !(*stack) || !(*stack)->next)
        return;
    if ((*stack)->value > (*stack)->next->value)
        do_swap(stack, 'a');
}

void	ft_sort_three(t_stack **stack)
{
    int	a;
    int	b;
    int	c;

    if (!stack || !(*stack) || !(*stack)->next || !(*stack)->next->next)
        return;
    a = (*stack)->value;
    b = (*stack)->next->value;
    c = (*stack)->next->next->value;
    if (a > b && b < c && a < c)
        do_swap(stack, 'a');
    else if (a > b && b > c)
    {
        do_swap(stack, 'a');
        do_reverse_rotate(stack, 'a');
    }
    else if (a > b && b < c && a > c)
        do_rotate(stack, 'a');
    else if (a < b && b > c && a < c)
    {
        do_swap(stack, 'a');
        do_rotate(stack, 'a');
    }
    else
        do_reverse_rotate(stack, 'a');
}

void ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
    if (!stack_a || !(*stack_a) || !stack_b || ft_stacksize(*stack_a) != 4 || is_sorted(stack_a))
        return;

    ft_min_to_top(stack_a, 'a');
    do_push(stack_a, stack_b, 'b');
    ft_sort_three(stack_a);
    if (*stack_b)
        do_push(stack_a, stack_b, 'a');
    if ((*stack_a)->value > (*stack_a)->next->value)
        do_rotate(stack_a, 'a');
}

void ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
    if (!stack_a || !(*stack_a) || !stack_b || ft_stacksize(*stack_a) != 5 || is_sorted(stack_a))
        return;

    ft_min_to_top(stack_a, 'a');
    do_push(stack_a, stack_b, 'b');
    ft_sort_four(stack_a, stack_b);
    if (*stack_b)
        do_push(stack_a, stack_b, 'a');
    if ((*stack_a)->value > (*stack_a)->next->value)
        do_rotate(stack_a, 'a');
}
