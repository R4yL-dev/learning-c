/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:49:52 by lray              #+#    #+#             */
/*   Updated: 2023/02/19 19:55:42 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

void	ft_push(t_stack **stack, int data)
{
	t_stack	*newNode;

	newNode = ft_newNode(data);
	*stack = newNode;
}

int	ft_pop(t_stack **stack)
{
	t_stack	*tmp;
	int		resp;

	if (ft_isEmpty(*stack))
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	resp = tmp->data;
	free(tmp);
	return (resp);
}

int pop(t_stack** root)
{
	if (ft_isEmpty(*root))
		return 0;
	t_stack* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}
