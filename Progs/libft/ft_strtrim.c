/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:28:02 by lray              #+#    #+#             */
/*   Updated: 2022/10/31 17:12:17 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		Alloue et retourne une coipe de la chaine s1, sans les caractères dans
		set au début et à la fin de la chaine de caractères.

	Params :
		- s1 : La chaine de caractères à trimmer
		- set : Le set de référence de caractères à trimmer.

	Ret :
		- La chaine de caractères trimmée
		- NULL si l'allocation échoue
*/

/*
	Définir la taille de l'allocation à strlen(s1) + 1.
	Regarder si s1 commence par set.
	Si oui, copier s1 dans resp sans set
	Si non, copier s1 dans resp.
	Regarder si resp fini par set.
	Si oui, remplacer set de fin de resp par \0 et retourner resp.
	Si non, retourner resp.
*/

#include "libft.h"
#include <stdlib.h>

static int	def_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	state;

	state = 0;
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				state = 0;
				break ;
			}
			state = 1;
			j++;
		}
		if (state)
			return (i);
		i++;
	}
	return (0);
}

static int	def_end(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	state;

	state = 0;
	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				state = 0;
				break ;
			}
			state = 1;
			j++;
		}
		if (state)
			return (i);
		i--;
	}
	return (0);
}

static char	*make_cpy(char const *s1, char *buf, int s, int e)
{
	size_t	i;
	size_t	j;

	i = s;
	j = 0;
	while ((int)i <= e)
	{
		buf[j] = s1[i];
		i++;
		j++;
	}
	buf[j] = '\0';
	return (buf);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*resp;
	int		start_cpy;
	int		end_cpy;

	resp = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!resp)
		return (NULL);
	if (!s1[0] || !set[0])
	{
		start_cpy = 0;
		end_cpy = ft_strlen(s1);
	}
	else
	{
		start_cpy = def_start(s1, set);
		end_cpy = def_end(s1, set);
	}
	make_cpy(s1, resp, start_cpy, end_cpy);
	return (resp);
}
