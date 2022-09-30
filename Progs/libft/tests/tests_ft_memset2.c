/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_memset2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:23:21 by luca              #+#    #+#             */
/*   Updated: 2022/09/30 15:45:02 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	arr[10];
	size_t	i;

	ft_memset(arr, 'a', 10 * (sizeof(arr[0])));
	i = 0;
	while (i <= 9)
	{
		printf("arr[%ld] = %c\n", i, (char)arr[i]);
		i++;
	}
	return (0);
}
