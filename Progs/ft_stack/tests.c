/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:35:12 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 22:56:52 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <stdio.h>

int	main(void)
{
	t_stack	*stack;

	stack = NULL;
	ft_stkpush(&stack, 10);
	ft_stkpush(&stack, 20);
	ft_stkpush(&stack, 30);
	ft_stkpush(&stack, 40);
	printf("Stack size : %d\n", ft_stksize(stack));
	while (stack)
		printf("%d\n", ft_stkpop(&stack));
	printf("Stack size : %d\n", ft_stksize(stack));
	ft_stkclear(&stack);
	return (0);
}
