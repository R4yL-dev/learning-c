/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_strchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 16:57:47 by luca              #+#    #+#             */
/*   Updated: 2022/10/05 20:59:01 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	*s1 = "salut les amis";
	char	*resp1;
	char	*resp2;
	int		i;
	int		err;

	err = 0;
	i = -10;
	while (i <= 250)
	{
		resp1 = ft_strchr(s1, i);
		resp2 = strchr(s1, i);
		if (resp1 != resp2)
		{
			printf("[Err] result of ft_strchr don't match with\
			result of strchr\n");
			printf("[Inf] #%d %p != %p\n | char %c\n", i, resp1, resp2, i);
			err++;
		}
		i++;
	}
	printf("[Inf] test end with %d error(s)\n", err);
	return (0);
}
