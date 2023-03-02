/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:25:34 by lray              #+#    #+#             */
/*   Updated: 2023/03/02 14:43:09 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	db_show_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	ft_printf("--- Stack A ---\n");
	tmp = *stack_a;
	while (tmp)
	{
		ft_printf("- %d\n", ft_stkpeek(tmp));
		tmp = tmp->next;
	}
	ft_printf("--- Stack B ---\n");
	tmp = *stack_b;
	while (tmp)
	{
		ft_printf("- %d\n", ft_stkpeek(tmp));
		tmp = tmp->next;
	}
	ft_printf("\n");
	free(tmp);
}

void	db_show_size(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("Stack A Size : %d | Stack B Size : %d\n", \
		ft_stksize(*stack_a), ft_stksize(*stack_b));
}
