/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:25:34 by lray              #+#    #+#             */
/*   Updated: 2023/03/01 15:59:10 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stack.h"
#include <stdio.h>

void	db_show_stack(t_stack **stack)
{
	if (ft_stksize(*stack) > 0)
	{
		while (*stack)
			printf("%d\n", ft_stkpop(stack));
	}
}
