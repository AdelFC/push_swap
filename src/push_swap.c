/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:27:05 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/06 21:25:34 by afodil-c         ###   ########.fr       */
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

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
    if (!stack_a || !(*stack_a) || is_sorted(stack_a))
        return;

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
        return;

    ft_push_except_three(stack_a, stack_b);
    ft_sort_three(stack_a);
    while (*stack_b)
    {
        assign_target_positions(stack_a, stack_b);
        ft_cost(stack_a, stack_b);
        execute_cheapest_move(stack_a, stack_b);
    }
    if (!is_sorted(stack_a))
        ft_rotate_to_min(stack_a);
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int stack_size;
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
