/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_isascii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:10:21 by lray              #+#    #+#             */
/*   Updated: 2022/09/30 15:45:38 by lray             ###   ########.fr       */
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
	i = -10;
	while (i <= 100000)
	{
		if (argc >= 2)
			printf("Test #%d \t|\tft_isascii(%c) = %d [STD] = %d.\n"\
					, i, i, ft_isascii(i), isascii(i));
		if (ft_isascii(i) != isascii(i))
		{
			printf("[ERR] char = %c / %d | ft_isascii = %d - isascii = %d.\n"\
					, i, i, ft_isascii(i), isascii(i));
			err++;
		}
		i++;
	}
	printf("Test finish with %d error(s).\n", err);
}
