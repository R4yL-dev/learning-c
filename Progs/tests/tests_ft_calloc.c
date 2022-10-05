/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_calloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:23:33 by lray              #+#    #+#             */
/*   Updated: 2022/10/05 20:57:54 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	int	*tab;
	int	nbr_el;
	int	i;

	nbr_el = 10;
	tab = ft_calloc(nbr_el, sizeof(int));
	i = 0;
	printf("Total number of el = %d\n", nbr_el);
	while (i < nbr_el)
	{
		printf("el #%d% d\n", i, tab[i]);
		i++;
	}
	i = 0;
	printf("================\n");
	while (i < nbr_el)
	{
		printf("el #%d% d\n", i, tab[i] + i);
		i++;
	}
	free(tab);
	return (0);
}
