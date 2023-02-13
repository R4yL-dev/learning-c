/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:19:50 by lray              #+#    #+#             */
/*   Updated: 2023/02/13 11:50:20 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* La fonction ft_memmove() copie n octets depuis la zone mémoire src vers la
*	zone mémoire dest.
* Les deux zones peuvent se chevaucher :
*	la copie s'effectue comme si src était d'abord copiée dans un
*	tableau temporaire ne chevauchant pas src ou dest puis copiée vers dest.
*
* La fonction retoure un pointeur sur dest.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*pt_src;
	char	*pt_dst;

	pt_dst = (char *)dst;
	pt_src = (char *)src;
	if ((pt_src == NULL) && (pt_dst == NULL))
		return (NULL);
	// Si la source est plus petite que la dest
	// et si la dest est plus petite que la src + n
	if ((pt_src < pt_dst) && (pt_dst < pt_src + n))
	{
		// On avance les pointer vers le dernier char
		pt_dst += n;
		pt_src += n;
		while (n)
		{
			// on copie la src dans la dst depuis la fin
			*--pt_dst = *--pt_src;
			n--;
		}
	}
	else
	{
		// on copie la src dans a dst depuis le debut
		while (n--)
			*pt_dst++ = *pt_src++;
	}
	return (dst);
}
