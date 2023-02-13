/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 23:30:20 by lray              #+#    #+#             */
/*   Updated: 2023/02/13 16:14:30 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*resp;

	fd = open("samples/read_error.txt", O_RDONLY);
	while (1)
	{
		resp = get_next_line(fd);
		printf("%s", resp);
		if (resp == NULL)
		{
			free(resp);
			break ;
		}
		free(resp);
	}
	return (0);
}
