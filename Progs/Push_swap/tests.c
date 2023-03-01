/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:35:12 by lray              #+#    #+#             */
/*   Updated: 2023/03/01 15:53:18 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <stdio.h>

int	main(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	ft_stkpush(&stack, 10);
	ft_stkpush(&stack, 20);
	ft_stkpush(&stack, 30);

	printf("Stack size : %d\n", ft_stksize(stack));
	mv_swap(&stack);

	printf("Stack size : %d\n", ft_stksize(stack));
	db_show_stack(&stack);

	printf("Stack size : %d\n", ft_stksize(stack));
	ft_stkclear(&stack);

	return (0);
}
