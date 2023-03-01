/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:09:56 by lray              #+#    #+#             */
/*   Updated: 2023/03/01 19:35:55 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <stdio.h>

static void	do_test(t_stack **stack_a, t_stack**stack_b);

int	main(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	// Check args and initialize stack a with result

	printf("Init stacks ...\n");
	stack_a = NULL;
	stack_b = NULL;
	do_test(&stack_a, &stack_b);
	return (0);
}

static void	do_test(t_stack **stack_a, t_stack**stack_b)
{
	ft_stkpush(stack_a, 10);
	ft_stkpush(stack_a, 20);
	ft_stkpush(stack_a, 30);
	ft_stkpush(stack_a, 40);
	ft_stkpush(stack_a, 50);
	ft_stkpush(stack_a, 60);
	db_show_stack(stack_a, stack_b);
	db_show_size(stack_a, stack_b);

	printf("-- RROTATE A --\n");
	mv_rrotate(stack_a);
	db_show_stack(stack_a, stack_b);
	db_show_size(stack_a, stack_b);

	printf("-- ROTATE A --\n");
	mv_rotate(stack_a);
	db_show_stack(stack_a, stack_b);
	db_show_size(stack_a, stack_b);

	printf("-- PUSH B --\n");
	mv_push(stack_b, stack_a);
	db_show_stack(stack_a, stack_b);
	db_show_size(stack_a, stack_b);

	printf("-- PUSH B --\n");
	mv_push(stack_b, stack_a);
	db_show_stack(stack_a, stack_b);
	db_show_size(stack_a, stack_b);

	printf("-- SWAP B --\n");
	mv_swap(stack_b);
	db_show_stack(stack_a, stack_b);
	db_show_size(stack_a, stack_b);

	printf("-- ROTATE B --\n");
	mv_rotate(stack_b);
	db_show_stack(stack_a, stack_b);
	db_show_size(stack_a, stack_b);

	printf("-- PUSH A --\n");
	mv_push(stack_a, stack_b);
	db_show_stack(stack_a, stack_b);
	db_show_size(stack_a, stack_b);

	printf("-- SWAP A --\n");
	mv_swap(stack_a);
	db_show_stack(stack_a, stack_b);
	db_show_size(stack_a, stack_b);

	printf("Clear stacks ...\n");
	ft_stkclear(stack_a);
	ft_stkclear(stack_b);
	db_show_size(stack_a, stack_b);
}
