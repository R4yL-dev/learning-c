/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:25:45 by lray              #+#    #+#             */
/*   Updated: 2022/11/07 22:59:22 by lray             ###   ########.fr       */
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

static char			**free_all(char **arr);
static unsigned int	count_strs(char const *s, char c);
static void			get_row(char **str, unsigned int *str_len, char c);

char	**ft_split(char const *s, char c)
{
	char			**resp;
	char			*str;
	unsigned int	i;
	unsigned int	nbr_strs;
	unsigned int	str_len;

	nbr_strs = count_strs(s, c);
	resp = malloc(sizeof(char *) * (nbr_strs + 1));
	if (!resp)
		return (NULL);
	str = (char *)s;
	str_len = 0;
	i = 0;
	while (i < nbr_strs)
	{
		get_row(&str, &str_len, c);
		resp[i] = malloc(sizeof(char) * (str_len + 1));
		if (resp[i] == NULL)
			return (free_all(resp));
		ft_strlcpy(resp[i], str, str_len + 1);
		i++;
	}
	resp[i] = NULL;
	return (resp);
}

static char	**free_all(char **arr)
{
	unsigned int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static unsigned int	count_strs(char const *s, char c)
{
	unsigned int	i;
	unsigned int	resp;

	if (!s[0])
		return (0);
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	resp = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			resp++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		resp++;
	return (resp);
}

static void	get_row(char **str, unsigned int *str_len, char c)
{
	unsigned int	i;

	*str += *str_len;
	*str_len = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*str_len)++;
		i++;
	}
}
