/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_memchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:19:25 by luca              #+#    #+#             */
/*   Updated: 2022/09/30 15:45:14 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;
	char	*resp;
	char	*resp2;
	int		c;
	size_t	n;

	str = "salut les amis";
	n = 13;
	c = 'i';
	resp = ft_memchr(str, c, n);
	resp2 = memchr(str, c, n);
	printf("addr in ft_memchr()\t= %p\n", resp);
	printf("addr in memchr()\t= %p\n", resp2);
	return (0);
}
