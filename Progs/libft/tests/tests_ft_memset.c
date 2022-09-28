/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_memset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 02:51:25 by luca              #+#    #+#             */
/*   Updated: 2022/09/28 03:42:48 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n);

int	main(void)
{
	char	*ptr1;
	char	*ptr2;
	char	str[20];
	size_t	i;

	ptr1 = ft_memset(str, 120, 11);
	ptr2 = memset(str, 120, 11);
	i = 0;
	while (i <= 20)
	{
		printf("ptr1[%ld] = %d | ptr2[%ld] = %d\n", i, ptr1[i], i, ptr2[i]);
		i++;
	}
	return (0);
}
