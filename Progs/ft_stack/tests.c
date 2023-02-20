/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:35:12 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 14:23:52 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <stdio.h>

int	main(void)
{
	t_stack	*stack;

	stack = NULL;
	ft_push(&stack, 10);
	ft_push(&stack, 20);
	ft_push(&stack, 30);
	while (stack != NULL)
	{
		printf("ft_peek() = %d\n", ft_peek(stack));
		printf("ft_pop() = %d\n", ft_pop(&stack));
	}
	return (0);
}
