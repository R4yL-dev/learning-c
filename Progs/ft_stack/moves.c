/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:02:01 by lray              #+#    #+#             */
/*   Updated: 2023/03/01 15:11:05 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"

/*
*	Entervertit les deux premiers nomber de la pile passée en paramètre
*/
void	swap(t_stack **stack)
{
	// Vérifi qu'il y ai au moins deux item dans la stack
	// Pop deux fois la liste en gardant les resultat.
	// Push le deuxieme resulat puis le premier
	if (ft_stksize(stack) >= 2)
	{
		t_stack *node1;
		t_stack	*node2;

		node1 = ft_stkpop(*stack);
		node2 = ft_stkpop(*stack);
		ft_stkpush(node1);
		ft_stkpush(node2);
	}
}
