/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:08:46 by lray              #+#    #+#             */
/*   Updated: 2023/05/14 02:03:24 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_img(t_game *game, t_img *img, unsigned int x, unsigned int y);

void	game_init(t_game *game, t_map *map)
{
	int	size_x;
	int	size_y;

	size_x = map->nbrs_cols * SPRITE_SIZE;
	size_y = map->nbrs_rows * SPRITE_SIZE;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, size_x, size_y, WIN_TITLE);
	game->map = map;
	img_load(game);
	game->nbrs_step = 0;
}

void	game_builder(t_game *game, t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < map->nbrs_rows)
	{
		x = 0;
		while (x < map->nbrs_cols)
		{
			if (get_cell(map, x, y) == '1')
				put_img(game, game->wall.img, x, y);
			else
				put_img(game, game->ground.img, x, y);
			if (get_cell(map, x, y) == 'C')
				put_img(game, game->item.img, x, y);
			else if ((x == map->exit->x) && (y == map->exit->y))
				put_img(game, game->map->exit->exit_sprit.img, x, y);
			else if ((x == map->player->x) && (y == map->player->y))
				put_img(game, game->map->player->player_sprit.img, x, y);
			x++;
		}
		y++;
	}
}

static void	put_img(t_game *game, t_img *img, unsigned int x, unsigned int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
		game->ground.img, x * 64, y * 64);
}

void	game_quit(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	map_free(game->map);
	img_delete(game);
	exit (EXIT_SUCCESS);
}
