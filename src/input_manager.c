/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:24:11 by afodil-c          #+#    #+#             */
/*   Updated: 2025/02/07 18:23:07 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_double(char **argv)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (argv[i])
	{
		tmp = ft_atol(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			if (tmp == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_stack *ft_initialize_stack(int argc, char **argv, t_stack *stack_a)
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

int	ft_check_args(int argc, char **argv)
{
	int		i;
	long	number;

	i = 1;
	if (argc < 2)
		return (ft_print_error(1), 1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	while (argv[i])
	{
		if (!ft_isnum(argv[i]))
			return (ft_print_error(3), 1);
		number = ft_atol(argv[i]);
		if (number < INT_MIN || number > INT_MAX)
			return (ft_print_error(4), 1);
		i++;
	}
	if (ft_check_double(argv))
		return (ft_print_error(2), 1);
	return (0);
}
