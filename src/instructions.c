/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:22:08 by afodil-c          #+#    #+#             */
/*   Updated: 2025/02/07 18:21:23 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(t_stack **stack)
{
    t_stack	*first;
    t_stack	*second;

    if (!stack || !(*stack) || !(*stack)->next)
        return;
    first = *stack;
    second = (*stack)->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}
void	do_swap(t_stack **stack, char type)
{
    ft_swap(stack);
    if (type == 'a')
        ft_printf("sa\n");
    else if (type == 'b')
        ft_printf("sb\n");
}

void	do_swap_both(t_stack **stack_a, t_stack **stack_b)
{
    ft_swap(stack_a);
    ft_swap(stack_b);
    ft_printf("ss\n");
}

void	ft_push(t_stack **src, t_stack **dest)
{
    t_stack	*tmp;

    if (!src || !(*src))
        return;
    tmp = *src;
    *src = (*src)->next;
    ft_stackadd_front(dest, tmp);
}

void	do_push(t_stack **stack_a, t_stack **stack_b, char type)
{
    if (type == 'a')
    {
        ft_push(stack_b, stack_a);
        ft_printf("pa\n");
    }
    else if (type == 'b')
    {
        ft_push(stack_a, stack_b);
        ft_printf("pb\n");
    }
}

void	ft_rotate(t_stack **stack)
{
    t_stack	*first;
    t_stack	*last;

    if (!stack || !(*stack) || !(*stack)->next)
        return;
    first = *stack;
    last = ft_stacklast(*stack);
    *stack = first->next;
    first->next = NULL;
    last->next = first;
}

void	do_rotate(t_stack **stack, char type)
{
    ft_rotate(stack);
    if (type == 'a')
        ft_printf("ra\n");
    else if (type == 'b')
        ft_printf("rb\n");
}

void	do_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
    ft_rotate(stack_a);
    ft_rotate(stack_b);
    ft_printf("rr\n");
}

void	ft_reverse_rotate(t_stack **stack)
{
    t_stack	*first;
    t_stack	*last;
    t_stack	*tmp;

    if (!stack || !(*stack) || !(*stack)->next)
        return;
    first = *stack;
    tmp = first;
    last = ft_stacklast(*stack);
    while (tmp->next != last)
        tmp = tmp->next;
    tmp->next = NULL;
    last->next = *stack;
    *stack = last;
}

void	do_reverse_rotate(t_stack **stack, char type)
{
    ft_reverse_rotate(stack);
    if (type == 'a')
        ft_printf("rra\n");
    else if (type == 'b')
        ft_printf("rrb\n");
}

void	do_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
    ft_reverse_rotate(stack_a);
    ft_reverse_rotate(stack_b);
    ft_printf("rrr\n");
}
