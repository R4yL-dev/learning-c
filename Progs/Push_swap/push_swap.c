/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:09:56 by lray              #+#    #+#             */
/*   Updated: 2023/03/02 13:21:39 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *args[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		j;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	j = 0;
	if (argc < 2)
		exit(0);
	while (i < argc)
	{
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
			{
				ft_printf("Error\n");
				ft_stkclear(&stack_a);
				ft_stkclear(&stack_b);
				exit(1);
			}
			j++;
		}
		ft_stkpush(&stack_a, ft_atoi(args[i]));
		j = 0;
		i++;
	}

	db_show_stack(&stack_a, &stack_b);
	ft_stkclear(&stack_a);
	ft_stkclear(&stack_b);
	return (0);
}
