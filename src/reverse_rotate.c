/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:40:07 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/07 15:41:58 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
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
