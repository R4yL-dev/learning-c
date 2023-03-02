/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:09:56 by lray              #+#    #+#             */
/*   Updated: 2023/03/02 14:51:43 by lray             ###   ########.fr       */
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
	db_show_stack(&stack_a, &stack_b);
	ft_stkclear(&stack_a);
	ft_stkclear(&stack_b);
	return (0);
}

static void	init_stack(t_stack **stack_a, t_stack **stack_b, \
	int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc < 2)
		exit(0);
	while (i < argc)
	{
		while (argv[i][j])
		{
			if (j == 0 && argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				ft_puterror(stack_a, stack_b);
			j++;
		}
		if (ft_stkhas(stack_a, ft_atoi(argv[i])))
			ft_puterror(stack_a, stack_b);
		ft_stkpush(stack_a, ft_atoi(argv[i]));
		j = 0;
		i++;
	}
}
