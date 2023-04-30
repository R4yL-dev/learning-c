/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:54:47 by lray              #+#    #+#             */
/*   Updated: 2023/04/30 20:07:47 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dbmap_show_format(t_map *map)
{
	int	i;

	i = 0;
	while (map->content[i])
	{
		if (i % map->nbrs_cols == 0 && i != 0)
			ft_printf("\n");
		ft_printf("%c", map->content[i]);
		i++;
	}
	ft_printf("\n");
}

void	dbmap_show_infos(t_map *map)
{
	ft_printf("\n--------------------\n");
	ft_printf("MAP INFOS\n");
	ft_printf("map->content : %s\n", map->content);
	ft_printf("map->nbrs_rows : %d\n", map->nbrs_rows);
	ft_printf("map->nbrs_cols : %d\n", map->nbrs_cols);
	ft_printf("--------------------\n\n");
}
