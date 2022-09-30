/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_strrchr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:28:24 by luca              #+#    #+#             */
/*   Updated: 2022/09/30 15:44:43 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
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
		resp1 = ft_strrchr(s1, i);
		resp2 = strrchr(s1, i);
		printf("addr with ft_strchr() = %p | addr with strchr(\
		) = %p | char = %c\n", resp1, resp2, i);
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
