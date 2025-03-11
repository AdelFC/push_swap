/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 22:51:07 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/10 10:51:34 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_loop(t_stack **stack_a, t_stack **stack_b, int size, int *count)
{
	int	i;

	i = 0;
	while (size > 6 && i < size && *count < size / 2)
	{
		if ((*stack_a)->index == -1)
			return ;
		if ((*stack_a)->index <= size / 2)
		{
			do_push(stack_a, stack_b, 'b');
			(*count)++;
		}
		else
			do_rotate(stack_a, 'a');
		i++;
	}
}
