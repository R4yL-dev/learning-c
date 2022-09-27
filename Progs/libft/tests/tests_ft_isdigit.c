/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_isdigit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:33:16 by lray              #+#    #+#             */
/*   Updated: 2022/09/27 17:35:45 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isdigit(int c);

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
