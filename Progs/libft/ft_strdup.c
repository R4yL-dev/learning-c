/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:33:57 by lray              #+#    #+#             */
/*   Updated: 2022/10/05 20:46:28 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		size;
	int		i;
	char	*resp;

	size = ft_strlen(s);
	resp = (char *)malloc(sizeof(char) * (size + 1));
	if (resp == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(resp + i) = *(char *)(s + i);
		i++;
	}
	resp[i] = '\0';
	return (resp);
}
