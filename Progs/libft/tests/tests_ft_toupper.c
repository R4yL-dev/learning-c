/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_toupper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:12:39 by luca              #+#    #+#             */
/*   Updated: 2022/09/28 17:24:24 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int ft_toupper(int c);

int	main(void)
{
	size_t i;

	i = -100;
	while(i <= 10000)
	{
		if (ft_toupper(i) != toupper(i))
			printf("[Err] #%ld %d != %d\n", i, ft_toupper(i), toupper(i));
		i++;
	}
	return (0);
}
