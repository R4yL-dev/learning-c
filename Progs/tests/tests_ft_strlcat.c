/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_strlcat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:58:34 by lray              #+#    #+#             */
/*   Updated: 2022/10/02 17:04:29 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

int	main(void)
{
	char buf[2048];
	char *str1 = "salut";
	char *str2 = " les amis";
	size_t resp;

	resp = ft_strlcat(buf, str1, sizeof(buf));
	printf("-= ADD STR 1 TO BUFFER =-\n");
	printf("resp = %ld\n", resp);
	printf("buffer = %s\n", buf);
	resp = ft_strlcat(buf, str2, sizeof(buf));
	printf("-= ADD STR 2 TO BUFFER =-\n");
	printf("resp = %ld\n", resp);
	printf("buffer = %s\n", buf);
	return (0);
}
