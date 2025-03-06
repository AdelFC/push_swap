/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:40:03 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/05 14:41:42 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
