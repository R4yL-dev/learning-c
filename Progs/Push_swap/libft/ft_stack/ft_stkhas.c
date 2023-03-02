/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkhas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:46:34 by lray              #+#    #+#             */
/*   Updated: 2023/03/02 14:16:59 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

int	ft_stkhas(t_stack **stack, int data)
{
	t_stack	*tmp;

	tmp = *stack;
	while (*stack)
	{
		if ((*stack)->data == data)
			return (1);
		*stack = (*stack)->next;
	}
	*stack = tmp;
	return (0);
}
