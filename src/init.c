/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:40:47 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/07 15:39:24 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_initialize_stack(int argc, char **argv, t_stack *stack_a)
{
	int	i;

	i = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = 0;
		while (argv[i])
		{
			ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi(argv[i])));
			i++;
		}
	}
	else if (argc > 2)
	{
		while (i < argc)
		{
			ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi(argv[i])));
			i++;
		}
	}
	return (stack_a);
}
