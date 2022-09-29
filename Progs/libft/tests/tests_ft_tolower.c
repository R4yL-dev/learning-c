/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_tolower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:48:41 by luca              #+#    #+#             */
/*   Updated: 2022/09/29 14:58:00 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_tolower(int c);

int	main(void)
{
	size_t i;
	size_t err;

	err = 0;
	i = 0;
	while(i <= 10000)
	{
		if (ft_tolower(i) != tolower(i))
		{
			printf("[Err] #%ld %d != %d\n", i, ft_tolower(i), tolower(i));
			err++;
		}
		i++;
	}
	printf("Tests finished with %ld error(s).\n", err);
	return (0);
}
