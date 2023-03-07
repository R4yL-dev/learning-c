/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:54:42 by lray              #+#    #+#             */
/*   Updated: 2023/03/07 16:16:20 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_last(t_stack **stack);
static void		exec_sa(t_stack **stack);
static void		exec_ra(t_stack **stack);
static void		exec_rra(t_stack **stack);

void	sort3(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;

	while (!is_sorted(stack_a))
	{
		first = *stack_a;
		last = get_last(stack_a);
		if (first->data < last->data && first->next->data > last->data)
		{
			exec_sa(stack_a);
			exec_ra(stack_a);
		}
		else if (first->data > first->next->data && first->data < last->data)
			exec_sa(stack_a);
		else if (first->data > last->data && first->data < first->next->data)
			exec_rra(stack_a);
		else if (first->data > first->next->data && first->data > last->data)
			exec_ra(stack_a);
		else
		{
			exec_ra(stack_a);
			exec_sa(stack_a);
		}
	}
}

/*
	I may put this fonction in the stack lib and use it on my code (rrotate, ..)
*/
static t_stack	*get_last(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*resp;

	tmp = (*stack);
	while ((*stack)->next && (*stack)->next->next)
		(*stack) = (*stack)->next;
	resp = (*stack)->next;
	(*stack) = tmp;
	return (resp);
}

static void	exec_sa(t_stack **stack)
{
	ft_printf("sa\n");
	mv_swap(stack);
}

static void	exec_ra(t_stack **stack)
{
	ft_printf("ra\n");
	mv_rotate(stack);
}

static void	exec_rra(t_stack **stack)
{
	ft_printf("ra\n");
	mv_rrotate(stack);
}
