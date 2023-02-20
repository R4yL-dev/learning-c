/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:49:52 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 14:23:32 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_push(t_stack **stack, int data)
{
	t_stack	*new_node;

	new_node = ft_new_node(data);
	new_node->next = *stack;
	*stack = new_node;
}

int	ft_pop(t_stack **stack)
{
	t_stack	*tmp;
	int		resp;

	if (ft_is_empty(*stack))
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	resp = tmp->data;
	free(tmp);
	return (resp);
}
