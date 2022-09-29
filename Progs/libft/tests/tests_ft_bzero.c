/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_bzero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:55:47 by luca              #+#    #+#             */
/*   Updated: 2022/09/29 15:57:11 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>

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
