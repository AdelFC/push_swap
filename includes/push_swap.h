/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:07:14 by afodil-c          #+#    #+#             */
/*   Updated: 2025/02/07 18:23:55 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/ftprintf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../utils/stack_utils.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void                ft_print_error(int code);

int                 ft_isnum(char *str);
int 	            ft_check_double(char **argv);
t_stack             *ft_initialize_stack(int argc, char **argv, t_stack *stack_a);
int	                ft_check_args(int argc, char **argv);

void                ft_swap(t_stack **stack);
void                do_swap(t_stack **stack, char type);
void                do_swap_both(t_stack **stack_a, t_stack **stack_b);
void                ft_push(t_stack **src, t_stack **dest);
void                do_push(t_stack **stack_a, t_stack **stack_b, char type);
void                ft_rotate(t_stack **stack);
void                do_rotate(t_stack **stack, char type);
void                do_rotate_both(t_stack **stack_a, t_stack **stack_b);
void                ft_reverse_rotate(t_stack **stack);
void                do_reverse_rotate(t_stack **stack, char type);
void                do_reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

void            	ft_print_stacks(t_stack *stack_a, t_stack *stack_b);
int                 main(int argc, char **argv);

void                sort_three(t_stack **stack);

#endif
