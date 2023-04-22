/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:51:58 by lray              #+#    #+#             */
/*   Updated: 2023/03/20 11:39:25 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort5(t_stack **stack_a, t_stack **stack_b)
{
	if (!is_sorted(stack_a))
	{
		while ((*stack_a)->data != 0)
			exec_rra(stack_a);
		exec_pb(stack_a, stack_b);
		while ((*stack_a)->data != 1)
			exec_rra(stack_a);
		exec_pb(stack_a, stack_b);
		sort3(stack_a);
		exec_pa(stack_a, stack_b);
		exec_pa(stack_a, stack_b);
	}
}
