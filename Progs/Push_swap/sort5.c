/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:51:58 by lray              #+#    #+#             */
/*   Updated: 2023/03/19 20:30:54 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_pa(t_stack **stack_a, t_stack **stack_b);
static void	exec_pb(t_stack **stack_a, t_stack **stack_b);
//static void	exec_sa(t_stack **stack);
//static void	exec_ss(t_stack **stack_a, t_stack **stack_b);
static void	exec_rra(t_stack **stack_a);
//static void	exec_rrb(t_stack **stack_b);
//static void	exec_ra(t_stack **stack);

void	sort5(t_stack **stack_a, t_stack **stack_b)
{
	if (!is_sorted(stack_a))
	{
		while ((*stack_a)->data != 0)
			exec_rra(stack_a);
		exec_pb(stack_a, stack_b);
		while ((*stack_a)->data != 1)
			exec_rra(stack_a);
		exec_pb(stack_a, stack_b);
		sort3(stack_a);
		exec_pa(stack_a, stack_b);
		exec_pa(stack_a, stack_b);
	}




/* 	if (!is_sorted(stack_a))
	{
		// Step 1
		exec_pb(stack_a, stack_b);
		exec_pb(stack_a, stack_b);
		exec_pb(stack_a, stack_b);
		// Step 2
		if((*stack_a)->data > (*stack_a)->next->data)
			exec_sa(stack_a);
		// Step 3
		if((*stack_b)->data > (*stack_a)->data)
			exec_ss(stack_a, stack_b);
		// Step 4
		while(*stack_b != NULL)
		{
			if((*stack_b)->data < (*stack_a)->data)
				exec_pa(stack_a, stack_b);
			else
			{
				exec_rrb(stack_b);
				exec_pa(stack_a, stack_b);
			}
		}
		// Step 5
		while((*stack_a)->next != NULL && (*stack_a)->next->data > (*stack_a)->data)
			exec_ra(stack_a);
	} */
}

static void	exec_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("pa\n");
	mv_push(stack_a, stack_b);
}

static void	exec_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("pb\n");
	mv_push(stack_b, stack_a);
}

/* static void	exec_sa(t_stack **stack)
{
	ft_printf("sa\n");
	mv_swap(stack);
} */

/* static void	exec_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("ss\n");
	mv_swap(stack_a);
	mv_swap(stack_b);
} */

static void	exec_rra(t_stack **stack_a)
{
	ft_printf("rra\n");
	mv_rrotate(stack_a);
}

/* static void	exec_rrb(t_stack **stack_b)
{
	ft_printf("rrb\n");
	mv_rrotate(stack_b);
} */

/* static void	exec_ra(t_stack **stack)
{
	ft_printf("ra\n");
	mv_rotate(stack);
} */
