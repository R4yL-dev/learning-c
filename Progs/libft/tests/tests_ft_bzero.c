/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_bzero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:55:47 by luca              #+#    #+#             */
/*   Updated: 2022/09/28 16:07:15 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	ft_bzero(void *s, size_t n);

int main(void)
{
	char str[] = "Salut les amis, comment aller vous ?";

	printf("%s\n", str);
	ft_bzero(str + 7, 30);
	printf("ft_bzero() = %s\n", str);
	bzero(str + 7, 30);
	printf("bzero() = %s\n", str);
	return (0);
}
