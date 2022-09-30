/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_memcmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:36:54 by lray              #+#    #+#             */
/*   Updated: 2022/09/30 18:11:07 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str1 = "salut";
	char	*str2 = "sa";

	printf("%d\n", ft_memcmp(str1, str2, 3));
	printf("%d\n", memcmp(str1, str2, 3));
	return (0);
}
