/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:35:23 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/05 18:20:33 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnum(char *str)
{
    int	i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (0);
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
    long	tmp;

    i = 0;
    while (argv[i])
    {
        tmp = ft_atol(argv[i]);
        j = i + 1;
        while (argv[j])
        {
            if (tmp == ft_atol(argv[j]))
                return (-1);
            j++;
        }
        i++;
    }
    return (0);
}

int	ft_check_args(int argc, char **argv)
{
    int		i;
    long	number;
    char	**split_argv;

    i = 1;
    if (argc < 2)
        return (ft_print_error(1), -1);
    if (argc == 2)
    {
        split_argv = ft_split(argv[1], ' ');
        argv = split_argv;
        i = 0;
    }
    while (argv[i])
    {
        if (!ft_isnum(argv[i]))
            return (ft_print_error(3), -1);
        number = ft_atol(argv[i]);
        if (number < INT_MIN || number > INT_MAX)
            return (ft_print_error(4), -1);
        i++;
    }
    if (ft_check_double(argv))
        return (ft_print_error(2), -1);
    if (argc == 2)
        ft_free_split(split_argv);
    return (0);
}

void ft_free_split(char **split)
{
    int i;

    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}
