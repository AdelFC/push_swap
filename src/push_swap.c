/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:21:54 by afodil-c          #+#    #+#             */
/*   Updated: 2025/02/07 18:20:10 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;

	current_a = stack_a;
	current_b = stack_b;
	printf(" Stack A  | Stack B  \n");
	printf("----------------------\n");
	while (current_a || current_b)
	{
		if (current_a)
		{
			printf("  %5d   |", current_a->value);
			current_a = current_a->next;
		}
		else
			printf("       |");
		if (current_b)
		{
			printf("  %5d\n", current_b->value);
			current_b = current_b->next;
		}
		else
			printf("    \n");
	}
	printf("\n");
}

int main(int argc, char **argv)
{
    t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!ft_check_args(argc, argv))
	{
		stack_a = ft_initialize_stack(argc, argv, stack_a);
		ft_print_stacks(stack_a, stack_b);
		ft_print_stacks(stack_a, stack_b);
		ft_stackclear(&stack_a);
		ft_stackclear(&stack_b);
	}
	return (0);
}