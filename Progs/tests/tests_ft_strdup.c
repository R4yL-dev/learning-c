/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_strdup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 20:40:39 by lray              #+#    #+#             */
/*   Updated: 2022/10/05 20:59:12 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char *s1 = "Salut les amis !";
	char *s2;

	s2 = ft_strdup(s1);
	printf("%s\n", s2);
	free(s2);
	return (0);
}
