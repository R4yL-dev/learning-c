/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:05:53 by lray              #+#    #+#             */
/*   Updated: 2023/03/06 02:31:12 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//215392

void	try_sort(t_stack **stack_a, t_stack **stack_b)
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
			{
				//pb
				ft_printf("pb\n");
				mv_push(stack_b, stack_a);
			}
			else
			{
				//ra
				ft_printf("ra\n");
				mv_rotate(stack_a);
			}
		}
		while (ft_stksize(*stack_b) > 0)
		{
			//pa
			ft_printf("pa\n");
			mv_push(stack_a, stack_b);
		}
		i++;
	}
}
