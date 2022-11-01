/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:25:45 by lray              #+#    #+#             */
/*   Updated: 2022/11/01 19:03:32 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		Alloue et retourne un tableau de chaines de caractères obtenu en
		séparant s à l'aide du caractère c, utilisé comme délimiteur.
		Le tableau doit être terminé par NULL;

	Params :
		- s : La chaine de caractères à découper
		- c Le caractère délimiteur

	Ret :
		- Le tableau de nouvelles chaine de caractères résultant du découpage
		- NULL si l'allocation échoue
*/

#include "libft.h"
#include <stdlib.h>

static int	count_words(char const *s, char c);
static char	**init_string(char **arr, char const *s, char c);
static char	**make_strings(char **arr, char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		nbr_words;

	nbr_words = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * (nbr_words + 1));
	if (!arr)
		return (NULL);
	if (nbr_words == 0)
	{
		arr[0] = NULL;
		return (arr);
	}
	init_string(arr, (char *)s, c);
	make_strings(arr, (char *)s, c);
	return (arr);
}

static int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		words++;
		while (s[i] != c && s[i] != '\0')
			i++;
		i++;
	}
	return (words);
}

static char	**init_string(char **arr, char const *s, char c)
{
	int	size;
	int	i;
	int	j;

	i = 0;
	j = 0;
	size = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			size++;
			i++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
		arr[j] = (char *)malloc(sizeof(char) * (size + 1));
		size = 0;
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

static char	**make_strings(char **arr, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			arr[j][k] = s[i];
			k++;
			i++;
		}
		arr[j][k] = '\0';
		k = 0;
		j++;
		while (s[i] == c)
			i++;
	}
	return (arr);
}
