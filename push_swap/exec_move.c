/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:34:52 by lray              #+#    #+#             */
/*   Updated: 2023/03/20 11:39:27 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("pa\n");
	mv_push(stack_a, stack_b);
}

void	exec_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("pb\n");
	mv_push(stack_b, stack_a);
}

void	exec_sa(t_stack **stack)
{
	ft_printf("sa\n");
	mv_swap(stack);
}

void	exec_ra(t_stack **stack)
{
	ft_printf("ra\n");
	mv_rotate(stack);
}

void	exec_rra(t_stack **stack)
{
	ft_printf("rra\n");
	mv_rrotate(stack);
}
