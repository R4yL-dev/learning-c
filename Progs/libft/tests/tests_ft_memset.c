/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_memset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 02:51:25 by luca              #+#    #+#             */
/*   Updated: 2022/09/29 15:55:04 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*ptr1;
	char	*ptr2;
	char	str[12];
	size_t	i;
	size_t	err;

	err = 0;
	ptr1 = ft_memset(str, 0, 12 * sizeof(str[0]));
	ptr2 = memset(str, 0, 12 * sizeof(str[0]));
	i = 0;
	while (i <= 11)
	{
		printf("ptr1[%ld] = %d | ptr2[%ld] = %d\n", i, ptr1[i], i, ptr2[i]);
		if (ptr1[i] != ptr2[i])
		{
			printf("[ERR] ptr1[%ld] != ptr2[%ld] | %c - %c\n", i, i, ptr1[i], ptr2[i]);
			err++;
		}
		i++;
	}
	printf("[T] tests end with %ld error(s)\n", err);
	return (0);
}
