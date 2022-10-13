/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:16:36 by luca              #+#    #+#             */
/*   Updated: 2022/10/13 22:53:31 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* La fonction ft_memcpy() copie n octets depuis la zone mémoire src vers
*	la zone mémoire dest.
* Les deux zones ne doivent pas se chevaucher.
* Si c'est le cas, utilisez plutôt ft_memmove().
*
* Elle retourne un pointeur sur dest.
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*p_src;

	p_src = (char *)src;
	i = 0;
	while (i < n)
	{
		ft_memset((char *)((char *)dest + i), *(p_src + i), 1);
		i++;
	}
	return (dest);
}
