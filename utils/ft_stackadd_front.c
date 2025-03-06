/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:45:37 by afodil-c          #+#    #+#             */
/*   Updated: 2025/01/23 10:49:34 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}
