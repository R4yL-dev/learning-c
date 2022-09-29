/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:27:02 by luca              #+#    #+#             */
/*   Updated: 2022/09/29 20:00:04 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
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
			resp = &str[i];
		i++;
	}
	return (resp);
}
