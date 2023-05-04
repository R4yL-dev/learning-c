/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:54:47 by lray              #+#    #+#             */
/*   Updated: 2023/05/03 14:49:32 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dbmap_show_format(t_map *map)
{
	int	i;

	i = 0;
	ft_printf("\n");
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
	ft_printf("map->content\t\t:\t%s\n", map->content);
	ft_printf("map->nbrs_rows\t\t:\t%d\n", map->nbrs_rows);
	ft_printf("map->nbrs_cols\t\t:\t%d\n", map->nbrs_cols);
	ft_printf("map->is_rectangle\t:\t%d\n", map->is_rectangle);
	ft_printf("map->is_surrounded\t:\t%d\n", map->is_surrounded);
	ft_printf("map->nbrs_items\t\t:\t%d\n", map->nbrs_items);
	if (map->player)
	{
		ft_printf("\n");
		ft_printf("map->player->x\t\t:\t%d\n", map->player->x);
		ft_printf("map->player->y\t\t:\t%d\n", map->player->y);
	}
	if (map->exit)
	{
		ft_printf("\n");
		ft_printf("map->exit->x\t\t:\t%d\n", map->exit->x);
		ft_printf("map->exit->y\t\t:\t%d\n", map->exit->y);
	}
	ft_printf("--------------------\n\n");
}
