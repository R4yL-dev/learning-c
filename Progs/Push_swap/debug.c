/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:25:34 by lray              #+#    #+#             */
/*   Updated: 2023/03/01 16:38:37 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <stdio.h>

void	db_show_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	printf("--- Stack A ---\n");
	tmp = *stack_a;
	while (tmp)
	{
		printf("- %d\n", ft_stkpeek(tmp));
		tmp = tmp->next;
	}
	printf("--- Stack B ---\n");
	tmp = *stack_b;
	while (tmp)
	{
		printf("- %d\n", ft_stkpeek(tmp));
		tmp = tmp->next;
	}
	printf("\n");
	free(tmp);




/* 	while (*stack_a)
		printf("%d\n", ft_stkpop(stack_a));
	printf("Stack B\n");
		printf("%d\n", ft_stkpop(stack_b)); */
}

void	db_show_size(t_stack **stack_a, t_stack **stack_b)
{
	printf("Stack A Size : %d | Stack B Size : %d\n", ft_stksize(*stack_a), ft_stksize(*stack_b));
}
