/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:54:40 by lray              #+#    #+#             */
/*   Updated: 2023/04/17 16:02:26 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	c = 'A';
	char	*str = "Salut 42 !!!";
	int		num = 42;
	int		resp = 0;

	resp = ft_printf("%c %s %p %d %i %u %x %X %%", c, str, &num, num, num, num, num, num);
	printf("\n");
	printf("resp ft_printf = %d\n", resp);
	resp = printf("%c %s %p %d %i %u %x %X %%", c, str, &num, num, num, num, num, num);
	printf("\n");
	printf("resp printf = %d\n", resp);
	return (0);
}
