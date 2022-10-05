/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_strnstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:13:51 by lray              #+#    #+#             */
/*   Updated: 2022/10/05 18:07:33 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	char *big = "S";
	char *little = "Salut les amis";
	char *resp;

	resp = ft_strnstr(big, little, 1);
	printf("resp = %s\n", resp);
	return (0);
}
