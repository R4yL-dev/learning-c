/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_bzero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:55:47 by luca              #+#    #+#             */
/*   Updated: 2022/10/05 20:59:59 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "Salut les amis, comment aller vous ?";

	printf("%s\n", str);
	ft_bzero(str + 7, 30);
	printf("ft_bzero() = %s\n", str);
	bzero(str + 7, 30);
	printf("bzero() = %s\n", str);
	return (0);
}
