/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:32:37 by lray              #+#    #+#             */
/*   Updated: 2023/05/13 20:10:01 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_hook(game.win, ON_DESTROY, 0, handler_closebtn, &game);
	mlx_hook(game.win, ON_KEYDOWN, 0, handler_keypress, &game);
	mlx_loop_hook(game.mlx, handler_loop, &game);
	mlx_loop(game.mlx);
	game_quit(&game);
	return (EXIT_SUCCESS);
}
