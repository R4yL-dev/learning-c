/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_memset3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luca <luca@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:41:48 by luca              #+#    #+#             */
/*   Updated: 2022/09/28 16:06:51 by luca             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n);
int	ft_strlen(char *str);

int	main(void)
{
	char arr[] = "Salut les amis comment allez-vous ?";

	printf("%s\n", arr);
	ft_memset(arr + 9, 'x', 14 * sizeof(char));
	printf("%s\n", arr);
	return (0);
}
