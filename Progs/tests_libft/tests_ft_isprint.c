/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_isprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:45:28 by lray              #+#    #+#             */
/*   Updated: 2022/10/05 20:58:20 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	int	err;

	(void)argv;
	err = 0;
	i = -10;
	while (i <= 10000)
	{
		if (argc >= 2)
			printf("Test #%d \t|\tft_isctrl(%c) = %d [STD] = %d.\n"\
					, i, i, ft_isctrl(i), isctrl(i));
		if (ft_isctrl(i) != isctrl(i))
		{
			printf("[ERR] char = %c / %d | ft_isctrl = %d - isctrl = %d.\n"\
					, i, i, ft_isctrl(i), isctrl(i));
			err++;
		}
		i++;
	}
	printf("Test finish with %d error(s).\n", err);
}
