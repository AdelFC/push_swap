/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:48:52 by afodil-c          #+#    #+#             */
/*   Updated: 2025/01/23 11:38:46 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

void	ft_stackiter(t_stack *stack, void (*f)(int))
{
	while (stack)
	{
		f(stack->value);
		stack = stack->next;
	}
}
