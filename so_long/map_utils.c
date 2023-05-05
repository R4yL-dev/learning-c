/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:40:59 by lray              #+#    #+#             */
/*   Updated: 2023/05/05 17:49:11 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_init(t_map **map)
{
	(*map) = malloc(sizeof(t_map));
	(*map)->player = malloc(sizeof(t_player));
	(*map)->exit = malloc(sizeof(t_exit));
	if (!(*map) || !(*map)->player || !(*map)->exit)
	{
		put_error("Malloc failed");
		return (0);
	}
	(*map)->content = NULL;
	(*map)->nbrs_cols = 0;
	(*map)->nbrs_rows = 0;
	(*map)->is_rectangle = 1;
	(*map)->is_surrounded = 0;
	(*map)->nbrs_items = 0;
	(*map)->player->x = 0;
	(*map)->player->y = 0;
	(*map)->exit->x = 0;
	(*map)->exit->y = 0;
	return (1);
}

int	map_copy(t_map *map, t_map *copy)
{
	copy->content = malloc(sizeof(char) * ft_strlen(map->content));
	if (!copy->content)
	{
		put_error("Malloc failed");
		return (0);
	}
	ft_strlcpy(copy->content, map->content, ft_strlen(map->content) + 1);
	copy->nbrs_cols = map->nbrs_cols;
	copy->nbrs_rows = map->nbrs_rows;
	copy->is_rectangle = map->is_rectangle;
	copy->is_surrounded = map->is_surrounded;
	copy->nbrs_items = map->nbrs_items;
	copy->player->x = map->player->x;
	copy->player->y = map->player->y;
	copy->exit->x = map->exit->x;
	copy->exit->y = map->exit->y;
	return (1);
}

void	map_free(t_map *map)
{
	if (map)
	{
		if (map->content)
			free(map->content);
		if (map->player)
			free(map->player);
		if (map->exit)
			free(map->exit);
		free(map);
		map = NULL;
	}
}
