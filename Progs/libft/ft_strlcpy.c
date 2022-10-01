/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:34:04 by lray              #+#    #+#             */
/*   Updated: 2022/10/01 22:26:50 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* La fonction ft_strlcpy copie size - 1 octets de src vers dest.
* Le dernier octet de la dest est forcement le caractère '\0'.
*
* ft_strlcpy retourne la longueur de src.
*/

#include "libft.h"
#include <stdio.h>

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (!dest || !src)
		return (0);
	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (ft_strlen(src));
}
