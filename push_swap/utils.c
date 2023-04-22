/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:34:37 by lray              #+#    #+#             */
/*   Updated: 2023/03/20 14:47:37 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_puterror(t_stack **stack_a, t_stack **stack_b)
{
	write(2, "Error\n", 6);
	ft_stkclear(stack_a);
	ft_stkclear(stack_b);
	exit(1);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack);
	while (*stack && (*stack)->next)
	{
		if ((*stack)->data > (*stack)->next->data)
		{
			(*stack) = tmp;
			return (0);
		}
		*stack = (*stack)->next;
	}
	(*stack) = tmp;
	return (1);
}

void	free_argv(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i <= argc)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	choose_sort(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (argc == 2)
		sort2(stack_a);
	else if (argc == 3)
		sort3(stack_a);
	else if (argc == 5)
		sort5(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}
