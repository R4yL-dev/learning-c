/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_strncpm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:46:44 by luca              #+#    #+#             */
/*   Updated: 2022/09/29 19:03:37 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s1;
	char *s2;
	int r1;
	int r2;
	int n;

	n = 7;
	s1 = "Salut les amis";
	s2 = "Salut mes amis";
	r1 = ft_strncmp(s1, s2, n);
	r2 = strncmp(s1, s2, n);
	printf("r1 = %d | r2 = %d\n", r1, r2);
	return (0);
}
