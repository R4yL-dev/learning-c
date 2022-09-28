/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_isctrl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:30:43 by luca              #+#    #+#             */
/*   Updated: 2022/09/28 01:37:50 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isctrl(int c);

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
