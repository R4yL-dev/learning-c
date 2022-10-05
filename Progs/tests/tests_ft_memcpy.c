/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_memcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:27:32 by luca              #+#    #+#             */
/*   Updated: 2022/09/30 15:45:09 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[] = "salut les amis";
	char	s2[] = {'\0', '\0', '\0', '\0', '\0', '\0'};
	char	s3[] = {'\0', '\0', '\0', '\0', '\0', '\0'};

	ft_memcpy(s2, s1, 5);
	printf("[ft_memcpy]\ts1 = %s - s2 = %s\n", s1, s2);
	memcpy(s3, s1, 5);
	printf("[memcpy]\ts1 = %s - s3 = %s\n", s1, s3);
	return (0);
}
