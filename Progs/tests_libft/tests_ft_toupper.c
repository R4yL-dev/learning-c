/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_toupper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:12:39 by luca              #+#    #+#             */
/*   Updated: 2022/10/05 20:59:50 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	size_t	i;
	size_t	err;

	err = 0;
	i = 0;
	while (i <= 10000)
	{
		if (ft_toupper(i) != toupper(i))
		{
			printf("[Err] #%ld %d != %d\n", i, ft_toupper(i), toupper(i));
			err++;
		}
		i++;
	}
	printf("Tests finished with %ld error(s).\n", err);
	return (0);
}
