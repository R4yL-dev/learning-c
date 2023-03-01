/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stkpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:57:48 by lray              #+#    #+#             */
/*   Updated: 2023/02/20 23:14:55 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stkpush(t_stack **stack, int data)
{
	t_stack	*new_node;

	new_node = ft_stknew(data);
	new_node->next = *stack;
	*stack = new_node;
}
