/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:08:27 by lray              #+#    #+#             */
/*   Updated: 2022/09/30 18:17:57 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		res1;
	int		res2;

	if (n == 0)
		return (0);
	res1 = 0;
	res2 = 0;
	i = 0;
	while ((i < n) && (*(unsigned char *)(s1 + i) != 0 || \
		*(unsigned char *)(s2 + i) != 0))
	{
		res1 += *(unsigned char *)(s1 + i);
		res2 += *(unsigned char *)(s2 + i);
		i++;
	}
	if (res1 != res2)
		return (res1 - res2);
	return (0);
}
