/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:08:15 by luca              #+#    #+#             */
/*   Updated: 2022/09/30 19:39:07 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* La fonction memchr() examine les n premiers octets de la zone mémoire
*	pointée par s à la recherche de la première occurrence de c.
* À la fois s et les octets de la zone mémoire pointée par s sont
*	interprétés comme des unsigned char.
*/

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
