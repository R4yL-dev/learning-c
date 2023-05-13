/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:58:02 by lray              #+#    #+#             */
/*   Updated: 2023/05/13 18:59:22 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_collect_item(t_game *game)
{
	int				cell;
	unsigned int	player_x;
	unsigned int	player_y;

	player_x = game->map->player->x;
	player_y = game->map->player->y;
	cell = get_cell(game->map, player_x, player_y);
	if (cell == 'C')
	{
		set_cell(game->map, player_x, player_y, '0');
		game->map->nbrs_items--;
	}
}

void	game_switch_exit(t_game *game)
{
	if (game->map->nbrs_items == 0)
		game->map->exit->exit_sprit = game->exit_open;
}

void	game_is_ended(t_game *game)
{
	unsigned int	player_x;
	unsigned int	player_y;
	unsigned int	exit_x;
	unsigned int	exit_y;
	int				nbrs_items;

	player_x = game->map->player->x;
	player_y = game->map->player->y;
	exit_x = game->map->exit->x;
	exit_y = game->map->exit->y;
	nbrs_items = game->map->nbrs_items;
	if ((player_x == exit_x && player_y == exit_y) && nbrs_items == 0)
	{
		ft_printf("You won !!!\n");
		game_quit(game);
	}
}

void	game_draw_playground(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	game_builder(game, game->map);
}
