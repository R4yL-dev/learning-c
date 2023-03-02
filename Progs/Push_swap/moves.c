/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:02:01 by lray              #+#    #+#             */
/*   Updated: 2023/03/02 12:21:34 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Entervertit les deux premiers nomber de la pile passée en paramètre
*/
void	mv_swap(t_stack **stack)
{
	int	res1;
	int	res2;
	if (ft_stksize(*stack) >= 2)
	{
		res1 = ft_stkpop(stack);
		res2 = ft_stkpop(stack);
		ft_stkpush(stack, res1);
		ft_stkpush(stack, res2);
	}
}

/*
* Met le premier élément de stack2 dans stack1
*/
void	mv_push(t_stack **stack1, t_stack **stack2)
{
	int	res;

	if (!ft_stkisempty(*stack2))
	{
		res = ft_stkpop(stack2);
		ft_stkpush(stack1, res);
	}
}

void	mv_rotate(t_stack **stack)
{
	int		res;
	t_stack	*new_node;
	t_stack	*tmp;

	if (ft_stksize(*stack) >= 2)
	{
		res = ft_stkpop(stack);
		new_node = ft_stknew(res);
		tmp = (*stack);
		while ((*stack)->next)
			*stack = (*stack)->next;
		(*stack)->next = new_node;
		(*stack) = tmp;
	}
}

void	mv_rrotate(t_stack **stack)
{
	int		res;
	t_stack	*tmp;

	if (ft_stksize(*stack) >= 2)
	{
		tmp = (*stack);
		while ((*stack)->next && (*stack)->next->next)
		{
			(*stack)= (*stack)->next;
		}
		res = (*stack)->next->data;
		(*stack)->next = NULL;
		ft_stkpush(&tmp, res);
		(*stack) = tmp;
	}
}
