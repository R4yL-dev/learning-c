/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:36:28 by lray              #+#    #+#             */
/*   Updated: 2022/10/29 14:22:48 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Cette fonction prende deux strings en paramètres, big et little.
* Elle prend aussi un size_t len.
*
* La fonction cher dans big si elle trouve little. Elle compare les deux
*	strings sur len caractères. Les caractères qui sont appret '\0' ne
*	sont pas pris en compte.
*
* Parcourir big
*	Si le char big est égale au premier char de little
*		Mettre l'addresse du char de big dans le pointer
*		Parcourir big et little sur len char
*			Si big et little son les meme sur len char
*				Retourner pointer
*			Continuer a parcourir big
*		Continuer a parcourir big
*
* La fonction retourne :
*	- Si little est vide, big.
*	- Si little n'est pas trouver dans big, NULL
*	- Sinon, un pointer sur le premier caratères de la première occurance.
*
*	Utiliser ft_strncmp pour faire la comparaison.
*/

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t slen)
{
	char	c;
	char	sc;
	size_t	len;

	c = *find++;
	if (c != '\0')
	{
		len = ft_strlen(find);
		while (ft_strncmp(s, find, len) != 0)
		{
			while (sc != c)
			{
				sc = *s++;
				if (slen-- < 1 || sc == '\0')
					return (NULL);
			}
			if (len > slen)
				return (NULL);
		}
		s--;
	}
	return ((char *)s);
}
