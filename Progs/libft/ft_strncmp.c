/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:38:07 by luca              #+#    #+#             */
/*   Updated: 2022/09/30 19:22:22 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* La fonction ft_strncmp compare les n premier caractères des
*	deux strings s1 et s2.
*
* Elle retourne :
*	0, si s1 et s2 sont égale.
*	un nombre négatif si s1 est plus petit que s2.
*	un nombre positif si s1 est plus grand que s2.
* Les nombres renvoyés sont la différance entre les valeurs ascii
*	des premières caractères différants entre les deux chaine.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
