/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:27:02 by luca              #+#    #+#             */
/*   Updated: 2022/09/30 19:15:10 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* La fonction ft_strrchr retourne un pointer sur la dernière occurance
*	du caractère c dans la string s.
* Si la fonction ne trouve pas c dans s, elle retourn NULL.
*/

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
