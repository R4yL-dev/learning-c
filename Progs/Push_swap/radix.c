/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:05:53 by lray              #+#    #+#             */
/*   Updated: 2023/03/06 18:56:01 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_pb(t_stack **stack_a, t_stack **stack_b);
static void	exec_ra(t_stack **stack);
static void	exec_pa(t_stack **stack_a, t_stack **stack_b);

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	iterations;
	int	size;

	i = 0;
	size = ft_stksize(*stack_a);
	while (!is_sorted(stack_a))
	{
		iterations = 0;
		while (iterations < size)
		{
			iterations++;
			if ((((*stack_a)->data >> i) & 1) == 0)
				exec_pb(stack_a, stack_b);
			else
				exec_ra(stack_a);
		}
		while (ft_stksize(*stack_b) > 0)
			exec_pa(stack_a, stack_b);
		i++;
	}
}

static void	exec_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("pb\n");
	mv_push(stack_b, stack_a);
}

static void	exec_ra(t_stack **stack)
{
	ft_printf("ra\n");
	mv_rotate(stack);
}

static void	exec_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("pa\n");
	mv_push(stack_a, stack_b);
}
