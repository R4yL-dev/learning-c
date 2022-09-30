/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 15:43:28 by lray              #+#    #+#             */
/*   Updated: 2022/09/30 15:43:34 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	*resp;
	int		size;
	int		i;

	str = (char *)s;
	resp = NULL;
	size = ft_strlen(s);
	i = 0;
	while (i <= (size))
	{
		if (s[i] == c)
		{
			resp = &str[i];
			break ;
		}
		i++;
	}
	return (resp);
}
