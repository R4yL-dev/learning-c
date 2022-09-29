/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:16:36 by luca              #+#    #+#             */
/*   Updated: 2022/09/29 19:50:54 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*p_src;

	p_src = (char *)src;
	i = 0;
	while (i < n)
	{
		ft_memset((char *)(dest + i), *(p_src + i), 1);
		i++;
	}
	return (dest);
}
