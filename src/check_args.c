/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 13:35:23 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/08 14:17:38 by afodil-c         ###   ########.fr       */
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
	int		i;
	int		j;
	long	tmp;

	i = 1;
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

char	**ft_parse_args(int argc, char **argv, char ***split_argv)
{
	*split_argv = NULL;
	if (argc < 2)
	{
		ft_print_error(1);
		return (NULL);
	}
	if (argc == 2)
	{
		*split_argv = ft_split(argv[1], ' ');
		if (!*split_argv || !(*split_argv)[0])
		{
			ft_print_error(1);
			return (NULL);
		}
		return (*split_argv);
	}
	return (argv + 1);
}

int	ft_checker(char **argv, char **split_argv)
{
	char	**tmp;

	tmp = argv;
	while (*tmp)
	{
		if (!ft_isnum(*tmp) || ft_atol(*tmp) < INT_MIN
			|| ft_atol(*tmp) > INT_MAX)
		{
			if (split_argv)
				ft_free_split(split_argv);
			return (ft_print_error(1), -1);
		}
		tmp++;
	}
	if (ft_check_double(argv) != 0)
	{
		if (split_argv)
			ft_free_split(split_argv);
		return (ft_print_error(1), -1);
	}
	return (0);
}

int	ft_check_args(int argc, char **argv)
{
	char	**split_argv;
	char	**parsed_argv;

	parsed_argv = ft_parse_args(argc, argv, &split_argv);
	if (!parsed_argv)
	{
		ft_free_split(split_argv);
		return (-1);
	}
	if (ft_checker(parsed_argv, split_argv) != 0)
		return (-1);
	if (split_argv)
		ft_free_split(split_argv);
	return (0);
}
