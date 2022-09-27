/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_isalnum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:27:25 by lray              #+#    #+#             */
/*   Updated: 2022/09/27 17:36:20 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isalnum(int c);

int	main(int argc, char **argv)
{
	int	i;
	int	err;

	(void)argv;
	err = 0;
	i = 0;
	while (i <= 127)
	{
		if (argc >= 2)
			printf("Test #%d \t|\tft_isalnum(%c) = %d [STD] = %d.\n"\
					, i, i, ft_isalnum(i), isalnum(i));
		if (ft_isalnum(i) != isalnum(i))
		{
			printf("[ERR] char = %c / %d | ft_isalnum = %d - isalnum = %d.\n"\
					, i, i, ft_isalnum(i), isalnum(i));
			err++;
		}
		i++;
	}
	printf("Test finish with %d error(s).\n", err);
}
