/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_isdigit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:33:16 by lray              #+#    #+#             */
/*   Updated: 2022/09/29 15:45:17 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	int	err;

	(void)argv;
	err = 0;
	i = 0;
	while (i <= 10000)
	{
		if (argc >= 2)
			printf("Test #%d \t|\tft_isdigit(%c) = %d [STD] = %d.\n"\
					, i, i, ft_isdigit(i), isdigit(i));
		if (ft_isdigit(i) != isdigit(i))
		{
			printf("[ERR] char = %c / %d | ft_isdigit = %d - isdigit = %d.\n"\
					, i, i, ft_isdigit(i), isdigit(i));
			err++;
		}
		i++;
	}
	printf("Test finish with %d error(s).\n", err);
}
