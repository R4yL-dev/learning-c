/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_memmove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:44:10 by lray              #+#    #+#             */
/*   Updated: 2022/10/05 20:58:39 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	s1[] = "salut les amis";
	char	s2[] = {'\0', '\0', '\0', '\0', '\0', '\0'};
	char	s3[] = {'\0', '\0', '\0', '\0', '\0', '\0'};

	ft_memmove(s2, s1, 5);
	printf("[ft_memmove]\ts1 = %s - s2 = %s\n", s1, s2);
	memmove(s3, s1, 5);
	printf("[memmove]\ts1 = %s - s3 = %s\n", s1, s3);
	return (0);
}
