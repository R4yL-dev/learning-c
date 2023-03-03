/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:09:56 by lray              #+#    #+#             */
/*   Updated: 2023/03/03 12:17:20 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack **stack_a, t_stack **stack_b, \
	int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, &stack_b, argc, argv);
	ft_printf("Is stack A sorted ? %d\n", is_sorted(&stack_a));
	db_show_stack(&stack_a, &stack_b);
	ft_stkclear(&stack_a);
	ft_stkclear(&stack_b);
	return (0);
}

static void	init_stack(t_stack **stack_a, t_stack **stack_b, \
	int argc, char *argv[])
{
	int	i;

	argc -= 1;
	i = 0;
	if (argc < 1)
		exit(0);
	while (argc > 0)
	{
		while (argv[argc][i])
		{
			if (i == 0 && argv[argc][i] == '-')
				i++;
			if (!ft_isdigit(argv[argc][i]))
				ft_puterror(stack_a, stack_b);
			i++;
		}
		if (ft_stkhas(stack_a, ft_atoi(argv[argc])))
			ft_puterror(stack_a, stack_b);
		ft_stkpush(stack_a, ft_atoi(argv[argc]));
		i = 0;
		argc--;
	}
}
