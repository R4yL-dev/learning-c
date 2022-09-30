/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:08:15 by luca              #+#    #+#             */
/*   Updated: 2022/09/30 15:43:46 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*ptr;
	void	*str;
	size_t	i;

	ptr = NULL;
	str = (unsigned char *)s;
	i = 0;
	while (i < n && (*((unsigned char *)(str + i)) != '\0'))
	{
		if (*(unsigned char *)(str + i) == c)
		{
			ptr = (str + i);
			break ;
		}
		i++;
	}
	return (ptr);
}
