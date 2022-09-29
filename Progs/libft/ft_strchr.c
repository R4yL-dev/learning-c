/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:48:38 by luca              #+#    #+#             */
/*   Updated: 2022/09/29 19:59:31 by luca             ###   ########.fr       */
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
