/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:09:56 by lray              #+#    #+#             */
/*   Updated: 2023/03/06 02:14:06 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack **stack_a, t_stack **stack_b, \
	int argc, char *argv[]);
static void	add_to_stack(t_stack **stack_a, int argc, int *argv);

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit(0);
	if (argc == 2)
		argv = ft_split((const char *) argv[1], ' ');
	argc--;
	init_stack(&stack_a, &stack_b, argc, argv);
	db_show_result(&stack_a, &stack_b);
	try_sort(&stack_a, &stack_b);
	db_show_result(&stack_a, &stack_b);
	ft_stkclear(&stack_a);
	ft_stkclear(&stack_b);
	return (0);
}

static void	init_stack(t_stack **stack_a, t_stack **stack_b, \
	int argc, char *argv[])
{
	int	*resp;

	if (!check_args(argc, argv))
		ft_puterror(stack_a, stack_b);
	resp = sanitize(argc, argv);
	add_to_stack(stack_a, argc, resp);
	free(resp);
}

static void	add_to_stack(t_stack **stack_a, int argc, int *argv)
{
	while (argc >= 1)
	{
		ft_stkpush(stack_a, argv[argc]);
		argc--;
	}
}
