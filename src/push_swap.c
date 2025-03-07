/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:27:05 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/07 16:13:42 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (!stack_a || !(*stack_a) || is_sorted(stack_a))
		return ;
	if (stack_size == 2)
		ft_sort_two(stack_a);
	else if (stack_size == 3)
		ft_sort_three(stack_a);
	else if (stack_size == 4)
		ft_sort_four(stack_a, stack_b);
	else if (stack_size == 5)
		ft_sort_five(stack_a, stack_b);
	else
		ft_sort(stack_a, stack_b);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a || !stack_b)
		return ;
	ft_except_three(stack_a, stack_b);
	ft_sort_three(stack_a);
	while (*stack_b)
	{
		ft_target_position(stack_a, stack_b);
		ft_cost(stack_a, stack_b);
		ft_cheapest(stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
		ft_rotate_to_min(stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (!ft_check_args(argc, argv))
	{
		stack_a = ft_initialize_stack(argc, argv, NULL);
		stack_b = NULL;
		stack_size = ft_stacksize(stack_a);
		ft_index(stack_a, stack_size);
		push_swap(&stack_a, &stack_b, stack_size);
		ft_stackclear(&stack_a);
		ft_stackclear(&stack_b);
	}
	return (0);
}
