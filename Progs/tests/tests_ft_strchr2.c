/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_strchr2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:16:20 by luca              #+#    #+#             */
/*   Updated: 2022/10/05 20:59:05 by lray             ###   ########.fr       */
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

	resp1 = ft_strchr(s1, 0);
	resp2 = strchr(s1, 0);
	printf("[Inf] resp1 = %p | resp2 = %p\n", resp1, resp2);
	return (0);
}
