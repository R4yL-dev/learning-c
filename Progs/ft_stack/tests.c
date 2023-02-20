/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:35:12 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 16:58:01 by lray             ###   ########.fr       */
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
	printf("is empty ? %d\n", ft_is_empty(stack));
	ft_free_stack(&stack);
	printf("is empty ? %d\n", ft_is_empty(stack));
	return (0);
}
