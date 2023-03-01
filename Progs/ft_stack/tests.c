/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:35:12 by lray              #+#    #+#             */
/*   Updated: 2023/03/01 14:57:30 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <stdio.h>

void	runtest(void)
{
	t_stack	*stack;

	stack = NULL;
	ft_stkpush(&stack, 10);
	ft_stkpush(&stack, 20);
	ft_stkpush(&stack, 30);
	ft_stkpush(&stack, 40);
	printf("Stack size : %d\n", ft_stksize(stack));
	printf("Is stack empty ? %d\n", ft_stkisempty(stack));
	while (stack)
		printf("%d\n", ft_stkpop(&stack));
	printf("Stack size : %d\n", ft_stksize(stack));
	printf("Is stack empty ? %d\n", ft_stkisempty(stack));
	ft_stkclear(&stack);
}
