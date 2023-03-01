/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:02:01 by lray              #+#    #+#             */
/*   Updated: 2023/03/01 15:59:09 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

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
	if (!ft_stkisempty(*stack2))
		ft_stkpush(stack1, ft_stkpop(stack2));
}
