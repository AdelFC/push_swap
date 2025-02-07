/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:41:43 by afodil-c          #+#    #+#             */
/*   Updated: 2025/02/07 14:28:08 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H

# define STACK_UTILS_H

# include "../lib/libft/libft.h"

/*STRUCT DECLARATION*/
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

/*F DECLARATION*/
long				ft_atol(const char *nptr);
void				ft_stackadd_back(t_stack **stack, t_stack *new);
void				ft_stackadd_front(t_stack **stack, t_stack *new);
void				ft_stackclear(t_stack **stack);
void				ft_stackdelone(t_stack *stack);
void				ft_stackiter(t_stack *stack, void (*f)(int));
t_stack				*ft_stacklast(t_stack *stack);
t_stack				*ft_stacknew(int value);
int					ft_stacksize(t_stack *stack);

#endif