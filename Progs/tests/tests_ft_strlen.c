/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_strlen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 02:07:57 by luca              #+#    #+#             */
/*   Updated: 2022/10/05 20:59:27 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		printf("str = / %s / | ft_strlen = %ld | strlen = %ld\n"\
		, argv[1], ft_strlen(argv[1]), strlen(argv[1]));
	printf("\n");
	return (0);
}
