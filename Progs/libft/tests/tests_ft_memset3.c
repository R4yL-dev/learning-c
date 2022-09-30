/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_memset3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:41:48 by luca              #+#    #+#             */
/*   Updated: 2022/09/30 15:44:59 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	arr[50] = "Salut les amis comment allez-vous ?";

	printf("%s\n", arr);
	ft_memset(arr + 9, 'x', 14 * sizeof(char));
	printf("%s\n", arr);
	return (0);
}
