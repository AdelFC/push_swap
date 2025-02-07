/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:02:52 by afodil-c          #+#    #+#             */
/*   Updated: 2025/02/07 15:03:51 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(int code)
{
    // if (code)
    //     ft_printf("Error");
	if (code == 1)
		ft_printf("Error: At least one argument is required.\n");
	else if (code == 2)
		ft_printf("Error: All arguments must be different.\n");
	else if (code == 3)
		ft_printf("Error: All arguments must be integers.\n");
	else if (code == 4)
		ft_printf("Error: Integer value out of range (INT_MIN to INT_MAX).\n");
	else if (code == 5)
		ft_printf("Error: Invalid integer value.\n");
}
