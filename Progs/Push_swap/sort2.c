/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:30:57 by lray              #+#    #+#             */
/*   Updated: 2023/03/17 20:32:30 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_ra(t_stack **stack);

void	sort2(t_stack **stack_a)
{
	if (!is_sorted(stack_a))
		exec_ra(stack_a);
}

static void	exec_ra(t_stack **stack)
{
	ft_printf("ra\n");
	mv_rotate(stack);
}
