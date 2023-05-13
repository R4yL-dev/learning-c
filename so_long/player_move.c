/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:27:54 by lray              #+#    #+#             */
/*   Updated: 2023/05/14 01:18:17 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_left(t_game *game)
{
	int				new_cell;
	unsigned int	player_x;
	unsigned int	player_y;

	player_x = game->map->player->x;
	player_y = game->map->player->y;
	new_cell = get_cell(game->map, player_x - 1, player_y);
	if (new_cell != '1')
	{
		game->map->player->player_sprit = game->player_left;
		game->map->player->x = game->map->player->x - 1;
		return (1);
	}
	return (0);
}

int	move_right(t_game *game)
{
	int				new_cell;
	unsigned int	player_x;
	unsigned int	player_y;

	player_x = game->map->player->x;
	player_y = game->map->player->y;
	new_cell = get_cell(game->map, player_x + 1, player_y);
	if (new_cell != '1')
	{
		game->map->player->player_sprit = game->player_right;
		game->map->player->x = game->map->player->x + 1;
		return (1);
	}
	return (0);
}

int	move_up(t_game *game)
{
	int				new_cell;
	unsigned int	player_x;
	unsigned int	player_y;

	player_x = game->map->player->x;
	player_y = game->map->player->y;
	new_cell = get_cell(game->map, player_x, player_y - 1);
	if (new_cell != '1')
	{
		game->map->player->player_sprit = game->player_back;
		game->map->player->y--;
		return (1);
	}
	return (0);
}

int	move_down(t_game *game)
{
	int				new_cell;
	unsigned int	player_x;
	unsigned int	player_y;

	player_x = game->map->player->x;
	player_y = game->map->player->y;
	new_cell = get_cell(game->map, player_x, player_y + 1);
	if (new_cell != '1')
	{
		game->map->player->player_sprit = game->player_front;
		game->map->player->y++;
		return (1);
	}
	return (0);
}
