/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_strlcpy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 19:00:58 by lray              #+#    #+#             */
/*   Updated: 2022/10/01 22:27:37 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	char	buf[0];
	char	*str = "";
	size_t	resp;
	int		i;

	resp = ft_strlcpy(buf, str, sizeof(buf));
	printf("[TST] size of buffer : %ld\n", sizeof(buf));
	printf("[TST] buf = %s | resp = %ld\n", buf, resp);
	printf("[TST] len of str in buffer = %ld\n", ft_strlen(buf));
	printf("[TST] str in buffer = %s\n", buf);
	i = 0;
	while (i < 10)
	{
		printf("[TST] #%d %d - %c\n", i, buf[i], buf[i]);
		i++;
	}
	printf("%ld\n", ft_strlen(buf));
	printf("%ld\n", sizeof(buf));
	return (0);
}
