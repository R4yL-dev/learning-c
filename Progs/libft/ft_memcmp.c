/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:08:27 by lray              #+#    #+#             */
/*   Updated: 2022/09/30 19:37:06 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* La fonction ft_memcmp() compare les n premiers octets
*	(chacun interprété comme unsigned char) des zones mémoire s1 et s2.
*
* La fonction memcmp() renvoie un entier inférieur, égal ou supérieur
*	à zéro si les n premiers octets de s1 sont respectivement
*	inférieurs, égaux ou supérieurs aux n premiers octets de s2.
* Lorsque la valeur renvoyée est différente de zéro, elle est de même
*	signe que la différence entre les deux premiers octets
*	(interprétés comme unsigned  char) qui diffèrent dans s1 et s2.
* Lorsque la valeur renvoyée est différente de zéro, elle est de même
*	signe que la différence entre les deux premiers octets
*	(interprétés comme unsigned  char) qui diffèrent dans s1 et s2.
*/

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
