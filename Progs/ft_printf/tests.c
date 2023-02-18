/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:13:28 by lray              #+#    #+#             */
/*   Updated: 2023/02/18 22:47:25 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	resp1;
	int	resp2;

	resp1 = ft_printf("%% %c %s %d %i %x %X %p %u", \
		'x', "xxx", -2222, 2222, 2222, 2222, &resp1, 2222);
	ft_printf("\n");
	resp2 = printf("%% %c %s %d %i %x %X %p %u", \
		'x', "xxx", -2222, 2222, 2222, 2222, &resp1, 2222);
	printf("\nresp1 = %d\nresp2 = %d\n", resp1, resp2);
	return (0);
}
