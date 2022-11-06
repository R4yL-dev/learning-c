/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:08:50 by lray              #+#    #+#             */
/*   Updated: 2022/11/06 18:02:06 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*resp;

	if (!nmemb || !size)
		return (malloc(0));
	resp = malloc(nmemb * size);
	if (!resp)
		return (NULL);
	ft_memset((unsigned char *)resp, 0, nmemb * size);
	return (resp);
}
