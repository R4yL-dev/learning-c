/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:19:50 by lray              #+#    #+#             */
/*   Updated: 2022/09/30 19:30:50 by lray             ###   ########.fr       */
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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pt_tmp;
	unsigned char	*pt_dest;

	pt_tmp = (unsigned char *)src;
	pt_dest = (unsigned char *)dest;
	if (pt_tmp < pt_dest)
	{
		while (n > 0)
		{
			*(pt_dest + n) = *(pt_tmp + n);
			n--;
		}
	}
	else
		ft_memcpy(pt_dest, pt_tmp, n);
	return (dest);
}
