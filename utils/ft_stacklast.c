/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacklast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:49:06 by afodil-c          #+#    #+#             */
/*   Updated: 2025/01/31 08:06:23 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	if (stack == NULL)
		return (stack);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}
