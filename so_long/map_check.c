/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:12:06 by lray              #+#    #+#             */
/*   Updated: 2023/05/03 18:25:25 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_surrounded(t_map *map);
static int	valid_playground(t_map *map);
static int	valid_item(int item);
static int	store_data(t_map *map, unsigned int item, unsigned int x, unsigned int y);

int	map_check(t_map *map)
{
	if (!map->is_rectangle)
	{
		put_error("The map must be rectangular");
		return (0);
	}
	if (!is_surrounded(map))
	{
		put_error("The map must be surrounded by walls");
		return (0);
	}
	if (!valid_playground(map))
	{
		put_error("The map must be composed of 1 and 0 as well as a player, an exit and at least one collectible");
		return (0);
	}
	return (1);
}

static int	is_surrounded(t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while(x < map->nbrs_cols)
	{
		if (get_cell(map, x, 0) != '1' || get_cell(map, x, map->nbrs_rows - 1) != '1')
			return (0);
		x++;
	}
	y = 1;
	while (y < map->nbrs_rows - 1)
	{
		if (get_cell(map, 0, y) != '1' || get_cell(map, map->nbrs_cols - 1, y) != '1')
			return (0);
		y++;
	}
	map->is_surrounded = 1;
	return (1);
}

static int	valid_playground(t_map *map)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	item;

	y = 1;
	while (y < map->nbrs_rows - 1)
	{
		x = 1;
		while (x < map->nbrs_cols - 1)
		{
			item = get_cell(map, x, y);
			if (!valid_item(item))
				return (0);
			if (!store_data(map, item, x, y))
				return (0);
			x++;
		}
		y++;
	}
	if (map->nbrs_items == 0)
		return (0);
	return (1);
}

static int	valid_item(int item)
{
	if (item != '0' && item != '1' && item != 'P' && item != 'E' && item != 'C')
		return (0);
	return (1);
}

static int	store_data(t_map *map, unsigned int item, unsigned int x, unsigned int y)
{
	if (item == 'C')
		map->nbrs_items++;
	if (item == 'P')
	{
		if (map->player->x == 0 && map->player->y == 0)
		{
			map->player->x = x;
			map->player->y = y;
			set_cell(map, x, y, '0');
			return (1);
		}
		return (0);
	}
	if (item == 'E')
	{
		if (map->exit->x == 0 && map->exit->y == 0)
		{
			map->exit->x = x;
			map->exit->y = y;
			set_cell(map, x, y, '0');
			return (1);
		}
		return (0);
	}
	return (1);
}
