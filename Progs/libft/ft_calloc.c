/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:08:50 by lray              #+#    #+#             */
/*   Updated: 2022/10/13 22:50:31 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*resp;
	size_t	i;

	resp = NULL;
	if (nmemb == 0 || size == 0 || nmemb * size > INT_MAX)
		return (resp);
	resp = malloc(nmemb * size);
	if (resp == NULL)
		return (resp);
	i = 0;
	while (i < (nmemb * size))
	{
		*(char *)((char *)resp + i) = 0;
		i++;
	}
	return (resp);
}
