/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:32:37 by lray              #+#    #+#             */
/*   Updated: 2023/05/12 17:05:12 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	x_close(t_game *game);
static int	handler_keypress(int keycode, t_game *game);
static void move_left(t_game *game);
static void move_right(t_game *game);
static void move_up(t_game *game);
static void move_down(t_game *game);
static int	handler_loop(t_game *game);
static int	draw(t_game *game);
static int	has_won(t_game *game);
static int	is_on_item(t_game *game);
static int	change_exit_sprit(t_game *game);

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	game;

	map = NULL;
	if (!args_parser(&argc, &argv))
		exit (EXIT_FAILURE);
	if (!map_parser(&map, argv[0]) || !map_checker(map))
	{
		map_free(map);
		exit (EXIT_FAILURE);
	}
	game_init(&game, map);
	img_load(&game);
	mlx_hook(game.win, 17, 0, x_close, &game);
	mlx_hook(game.win, 2, 0, handler_keypress, &game);
	mlx_loop_hook(game.mlx, handler_loop, &game);
	mlx_loop(game.mlx);
	game_quit(&game);
	return (EXIT_SUCCESS);
}

static int	x_close(t_game *game)
{
	game_quit(game);
	return (1);
}

static int	handler_keypress(int keycode, t_game *game)
{
	if (keycode == 53)
		game_quit(game);
	if (keycode == 123 || keycode == 0)
		move_left(game);
	if (keycode == 124 || keycode == 2)
		move_right(game);
	if (keycode == 125 || keycode == 1)
		move_down(game);
	if (keycode == 126 || keycode == 13)
		move_up(game);
	return (1);
}

static void move_left(t_game *game)
{
	int	new_cel;

	new_cel = get_cell(game->map, game->map->player->x - 1, game->map->player->y);
	if (new_cel != '1')
	{
		game->map->player->player_sprit = game->player_left;
		game->map->player->x = game->map->player->x - 1;
	}
}

static void move_right(t_game *game)
{
	int	new_cel;

	new_cel = get_cell(game->map, game->map->player->x + 1, game->map->player->y);
	if (new_cel != '1')
	{
		game->map->player->player_sprit = game->player_right;
		game->map->player->x = game->map->player->x + 1;
	}
}

static void move_up(t_game *game)
{
	int	new_cel;

	new_cel = get_cell(game->map, game->map->player->x, game->map->player->y - 1);
	if (new_cel != '1')
	{
		game->map->player->player_sprit = game->player_back;
		game->map->player->y--;
	}
}

static void move_down(t_game *game)
{
	int	new_cel;

	new_cel = get_cell(game->map, game->map->player->x, game->map->player->y + 1);
	if (new_cel != '1')
	{
		game->map->player->player_sprit = game->player_front;
		game->map->player->y++;
	}
}

static int	handler_loop(t_game *game)
{
	is_on_item(game);
	change_exit_sprit(game);
	has_won(game);
	draw(game);
	return (1);
}

static int	has_won(t_game *game)
{
	if (game->map->player->x == game->map->exit->x && game->map->player->y == game->map->exit->y && game->map->nbrs_items == 0)
	{
		ft_printf("You won !!!\n");
		game_quit(game);
	}
	return (1);
}

static int	draw(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	game_builder(game, game->map);
	return (1);
}

static int	is_on_item(t_game *game)
{
	int cell = get_cell(game->map, game->map->player->x, game->map->player->y);
	if (cell == 'C')
	{
		set_cell(game->map, game->map->player->x, game->map->player->y, '0');
		game->map->nbrs_items--;
	}
	return (1);
}

static int	change_exit_sprit(t_game *game)
{
	if (game->map->nbrs_items == 0)
		game->map->exit->exit_sprit = game->exit_open;
	return (1);
}
