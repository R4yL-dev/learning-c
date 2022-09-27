/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_isprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 01:30:43 by luca              #+#    #+#             */
/*   Updated: 2022/09/28 01:37:50 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int c);

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
			printf("Test #%d \t|\tft_isprint(%c) = %d [STD] = %d.\n"\
					, i, i, ft_isprint(i), isprint(i));
		if (ft_isprint(i) != isprint(i))
		{
			printf("[ERR] char = %c / %d | ft_isprint = %d - isprint = %d.\n"\
					, i, i, ft_isprint(i), isprint(i));
			err++;
		}
		i++;
	}
	printf("Test finish with %d error(s).\n", err);
}
