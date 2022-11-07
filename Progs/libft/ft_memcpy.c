/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:16:36 by luca              #+#    #+#             */
/*   Updated: 2022/11/07 18:29:19 by lray             ###   ########.fr       */
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
	unsigned char		*p;
	const unsigned char	*q;

	if (src != dest)
	{
		p = dest;
		q = src;
		while (n--)
			*p++ = *q++;
	}
	return (dest);
}
