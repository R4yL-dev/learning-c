/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:26:14 by lray              #+#    #+#             */
/*   Updated: 2022/10/29 18:40:58 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		Alloue (avec malloc) et retourne une chaine de caractères
		issue de la chaine 's'.
		Cette nouvelle chaine commence à l'index 'start' et a pour
		taille maximale 'len'.

	Param :
		- s : La chaine de laquelle extraire la nouvelle chaine.
		- start : L'index de début de la nouvelle chaine dans la chaine 's'.
		- len : La taille maximale de la nouvelle chaine.

	Ret :
		- La nouvelle chaine de caractères.
		- NULL si l'allocation échoue.
*/

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*resp;
	size_t			i;

	if (s == NULL)
		return (NULL);
	if (len == 0 || start > ft_strlen(s))
	{
		resp = malloc(1);
		if (!resp)
			return (NULL);
		resp[0] = '\0';
		return (resp);
	}
	if (len > ft_strlen(s))
		resp = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		resp = malloc(sizeof(char) * (len + 1));
	if (!resp)
		return (NULL);
	i = 0;
	while (len-- && s[start])
	{
		resp[i] = s[start];
		start++;
		i++;
	}
	resp[i] = '\0';
	return (resp);
}
