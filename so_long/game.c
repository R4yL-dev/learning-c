/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:08:46 by lray              #+#    #+#             */
/*   Updated: 2023/05/12 17:05:17 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game, t_map *map)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, map->nbrs_cols * 64, map->nbrs_rows * 64, "so_long");
	game->map = map;
}

void	game_builder(t_game *game, t_map *map)
{
	unsigned int	x;
	unsigned int	y;
	char			item;

	y = 0;
	while (y < map->nbrs_rows)
	{
		x = 0;
		while (x < map->nbrs_cols)
		{
			item = get_cell(map, x, y);
			if (item != '1')
				mlx_put_image_to_window(game->mlx, game->win, game->ground.img, x * 64, y * 64);
			if (item == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall.img, x * 64, y * 64);
			if (item == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->item.img, x * 64, y * 64);
			if ((x == map->exit->x) && (y == map->exit->y))
				mlx_put_image_to_window(game->mlx, game->win, game->map->exit->exit_sprit.img, x * 64, y * 64);
			if ((x == map->player->x) && (y == map->player->y))
				mlx_put_image_to_window(game->mlx, game->win, game->map->player->player_sprit.img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	game_quit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	map_free(game->map);
	img_delete(game);
	exit (EXIT_SUCCESS);
}
