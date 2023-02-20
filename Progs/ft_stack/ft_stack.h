/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:49:48 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 16:46:46 by lray             ###   ########.fr       */
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
int		ft_pop(t_stack **stack);
t_stack	*ft_new_node(int data);
int		ft_is_empty(t_stack *stack);
int		ft_peek(t_stack *stack);
void	ft_free_stack(t_stack **stack);

#endif
