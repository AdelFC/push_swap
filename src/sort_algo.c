/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:22:31 by afodil-c          #+#    #+#             */
/*   Updated: 2025/02/07 18:09:30 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_stack **stack)
{
    int a;
    int b;
    int c;

    a = (*stack)->value;
    b = (*stack)->next->value;
    c = (*stack)->next->next->value;
    if (a < b && b < c)
        return;
    if (a < c && c < b)
        return;
    if (b < c && c < a)
        return;
    if (a > b && b < c && a < c)
        do_swap(stack, a);
    else if (a > b && b > c)
    {
        do_swap(stack, a);
        do_rotate(stack, a); 
    }
    else if (a > c && c > b)
        do_rotate(stack, a); 
}
