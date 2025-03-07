/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:50:17 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/07 16:19:17 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_stack *stack_a, int stack_size)
{
	t_stack	*p;
	t_stack	*max;
	int		value;

	while (--stack_size > 0)
	{
		p = stack_a;
		value = INT_MIN;
		max = NULL;
		while (p)
		{
			if (p->index == 0 && p->value >= value)
			{
				value = p->value;
				max = p;
			}
			p = p->next;
		}
		if (max)
			max->index = stack_size;
	}
}
