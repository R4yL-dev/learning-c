/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_memcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:27:32 by luca              #+#    #+#             */
/*   Updated: 2022/09/28 16:55:07 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

int	main(void)
{
	char s1[] = "salut les amis";
	char s2[] = {'\0', '\0', '\0', '\0', '\0', '\0'};
	char s3[] = {'\0', '\0', '\0', '\0', '\0', '\0'};

	ft_memcpy(s2, s1, 5);
	printf("[ft_memcpy]\ts1 = %s - s2 = %s\n", s1, s2);
	memcpy(s3, s1, 5);
	printf("[memcpy]\ts1 = %s - s3 = %s\n", s1, s3);
	return (0);
}
