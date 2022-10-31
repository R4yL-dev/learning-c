/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:08:48 by lray              #+#    #+#             */
/*   Updated: 2022/10/31 13:21:42 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	tsize;
	char	*resp;
	size_t	i;

	tsize = ft_strlen(s1) + ft_strlen(s2);
	resp = malloc(sizeof(char) * (tsize + 1));
	if (!resp)
		return (NULL);
	i = 0;
	while (*s1)
	{
		resp[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		resp[i] = *s2;
		i++;
		s2++;
	}
	resp[i] = '\0';
	return (resp);
}
