/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:49:48 by lray              #+#    #+#             */
/*   Updated: 2023/02/19 19:55:18 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# include <stdlib.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

void	ft_push(t_stack **stack, int data);
int	ft_pop(t_stack **stack);
t_stack	*ft_newNode(int	data);
int	ft_isEmpty(t_stack *stack);

int pop(t_stack** root);

#endif
