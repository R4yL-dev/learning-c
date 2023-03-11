/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:51:58 by lray              #+#    #+#             */
/*   Updated: 2023/03/11 18:41:48 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_pb(t_stack **stack_a, t_stack **stack_b);
static void	exec_pa(t_stack **stack_a, t_stack **stack_b);
static void	exec_rra(t_stack **stack_a);
static void	exec_ra(t_stack **stack);
static int	get_last_value(t_stack **stack);

void	sort5(t_stack **stack_a, t_stack **stack_b)
{
	if (!is_sorted(stack_a))
	{
		if (ft_stksize(*stack_a) == 5)
			exec_pb(stack_a, stack_b);
		exec_pb(stack_a, stack_b);
		sort3(stack_a);
		while (1)
		{
			if ((*stack_b)->data < (*stack_a)->data)
				exec_pa(stack_a, stack_b);
			else if ((*stack_b)->data > get_last_value(stack_a))
			{
				exec_pa(stack_a, stack_b);
				exec_rra(stack_a);
				while (!is_sorted(stack_a))
					exec_ra(stack_a);
			}
			else
			{
				while ((*stack_b)->data > (*stack_a)->data)
					exec_ra(stack_a);
				exec_pa(stack_a, stack_b);
				while (!is_sorted(stack_a))
					exec_rra(stack_a);
			}
			if (ft_stkisempty(*stack_b) && is_sorted(stack_a))
				break ;
		}
	}
}

static void	exec_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("pb\n");
	mv_push(stack_b, stack_a);
}

static void	exec_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("pa\n");
	mv_push(stack_a, stack_b);
}

static void	exec_rra(t_stack **stack_a)
{
	ft_printf("rra\n");
	mv_rrotate(stack_a);
}

static void	exec_ra(t_stack **stack)
{
	ft_printf("ra\n");
	mv_rotate(stack);
}

static int	get_last_value(t_stack **stack)
{
	t_stack	*tmp;
	int		resp;

	if ((*stack) == NULL)
		return (0);
	if ((*stack)->next == NULL)
		return (0);
	tmp = (*stack);
	while ((*stack)->next && (*stack)->next->next)
		(*stack) = (*stack)->next;
	resp = (*stack)->next->data;
	(*stack) = tmp;
	return (resp);
}
