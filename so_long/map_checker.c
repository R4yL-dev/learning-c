/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:12:06 by lray              #+#    #+#             */
/*   Updated: 2023/05/06 17:55:00 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_surrounded(t_map *map);
static int	valid_playground(t_map *map);
static int	store(t_map *m, unsigned int item, unsigned int x, unsigned int y);
static int	valid_path(t_map *map);

int	map_checker(t_map *map)
{
	if (!is_surrounded(map))
	{
		put_error("The map must be surrounded by walls");
		return (0);
	}
	if (!valid_playground(map))
	{
		put_error("The map must be composed of 1 and 0 as well \
as a player, an exit and at least one collectible");
		return (0);
	}
	if (!valid_path(map))
	{
		put_error("All collectibles and the exit must be accessible \
by the player.");
		return (0);
	}
	return (1);
}

static int	is_surrounded(t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < map->nbrs_cols)
	{
		if (get_cell(map, x, 0) != '1' || \
			get_cell(map, x, map->nbrs_rows - 1) != '1')
			return (0);
		x++;
	}
	y = 1;
	while (y < map->nbrs_rows - 1)
	{
		if (get_cell(map, 0, y) != '1' || \
			get_cell(map, map->nbrs_cols - 1, y) != '1')
			return (0);
		y++;
	}
	return (1);
}

static int	valid_playground(t_map *map)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	i;

	y = 1;
	while (y < map->nbrs_rows - 1)
	{
		x = 1;
		while (x < map->nbrs_cols - 1)
		{
			i = get_cell(map, x, y);
			if (i != '0' && i != '1' && i != 'P' && i != 'E' && i != 'C')
				return (0);
			if (!store(map, i, x, y))
				return (0);
			x++;
		}
		y++;
	}
	if (map->nbrs_items == 0)
		return (0);
	return (1);
}

static int	store(t_map *m, unsigned int item, unsigned int x, unsigned int y)
{
	if (item == 'C')
		m->nbrs_items++;
	if (item == 'P')
	{
		if (m->player->x == 0 && m->player->y == 0)
		{
			m->player->x = x;
			m->player->y = y;
			set_cell(m, x, y, '0');
			return (1);
		}
		return (0);
	}
	if (item == 'E')
	{
		if (m->exit->x == 0 && m->exit->y == 0)
		{
			m->exit->x = x;
			m->exit->y = y;
			set_cell(m, x, y, '0');
			return (1);
		}
		return (0);
	}
	return (1);
}

static int	valid_path(t_map *map)
{
	t_map	*copy;
	int		arr[2];
	int		resp;

	resp = 1;
	copy = NULL;
	arr[0] = 1;
	arr[1] = map->nbrs_items;
	map_init(&copy);
	map_copy(map, copy);
	flood(copy, map->player->x, map->player->y, arr);
	if (arr[0] != 0 || arr[1] != 0)
		resp = 0;
	map_free(copy);
	return (resp);
}
