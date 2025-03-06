/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:40:01 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/05 14:41:00 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
