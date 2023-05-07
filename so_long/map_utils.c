/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:40:59 by lray              #+#    #+#             */
/*   Updated: 2023/05/05 23:10:27 by lray             ###   ########.fr       */
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
	(*map)->nbrs_items = 0;
	(*map)->player->x = 0;
	(*map)->player->y = 0;
	(*map)->exit->x = 0;
	(*map)->exit->y = 0;
	return (1);
}

int	map_set_content(t_map *map, char *map_str)
{
	map->content = malloc(sizeof(char) * (ft_strlen(map_str) + 1));
	if (!map->content)
	{
		put_error("Malloc failed");
		return (0);
	}
	ft_strlcpy(map->content, map_str, ft_strlen(map_str) + 1);
	return (1);
}

int	map_copy(t_map *map, t_map *copy)
{
	copy->content = malloc(sizeof(char) * ft_strlen(map->content) + 1);
	if (!copy->content)
	{
		put_error("Malloc failed");
		return (0);
	}
	ft_strlcpy(copy->content, map->content, ft_strlen(map->content) + 1);
	copy->nbrs_cols = map->nbrs_cols;
	copy->nbrs_rows = map->nbrs_rows;
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
