/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:30:44 by lray              #+#    #+#             */
/*   Updated: 2023/05/11 17:55:06 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_load(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &game->wall.width, &game->wall.heigth);
	game->wall.addr = mlx_get_data_addr(game->wall.img, &game->wall.bpp, &game->wall.line_length, &game->wall.endian);

	game->ground.img = mlx_xpm_file_to_image(game->mlx, "assets/ground.xpm", &game->ground.width, &game->ground.heigth);
	game->ground.addr = mlx_get_data_addr(game->ground.img, &game->ground.bpp, &game->ground.line_length, &game->ground.endian);

	game->item.img = mlx_xpm_file_to_image(game->mlx, "assets/item.xpm", &game->item.width, &game->item.heigth);
	game->item.addr = mlx_get_data_addr(game->item.img, &game->item.bpp, &game->item.line_length, &game->item.endian);

	game->exit_close.img = mlx_xpm_file_to_image(game->mlx, "assets/exit1.xpm", &game->exit_close.width, &game->exit_close.heigth);
	game->exit_close.addr = mlx_get_data_addr(game->exit_close.img, &game->exit_close.bpp, &game->exit_close.line_length, &game->exit_close.endian);

	game->exit_open.img = mlx_xpm_file_to_image(game->mlx, "assets/exit2.xpm", &game->exit_open.width, &game->exit_open.heigth);
	game->exit_open.addr = mlx_get_data_addr(game->exit_open.img, &game->exit_open.bpp, &game->exit_open.line_length, &game->exit_open.endian);

	game->player_front.img = mlx_xpm_file_to_image(game->mlx, "assets/playerF.xpm", &game->player_front.width, &game->player_front.heigth);
	game->player_front.addr = mlx_get_data_addr(game->player_front.img, &game->player_front.bpp, &game->player_front.line_length, &game->player_front.endian);

	game->player_back.img = mlx_xpm_file_to_image(game->mlx, "assets/playerB.xpm", &game->player_back.width, &game->player_back.heigth);
	game->player_back.addr = mlx_get_data_addr(game->player_back.img, &game->player_back.bpp, &game->player_back.line_length, &game->player_back.endian);

	game->player_left.img = mlx_xpm_file_to_image(game->mlx, "assets/playerL.xpm", &game->player_left.width, &game->player_left.heigth);
	game->player_left.addr = mlx_get_data_addr(game->player_left.img, &game->player_left.bpp, &game->player_left.line_length, &game->player_left.endian);

	game->player_right.img = mlx_xpm_file_to_image(game->mlx, "assets/playerR.xpm", &game->player_right.width, &game->player_right.heigth);
	game->player_right.addr = mlx_get_data_addr(game->player_right.img, &game->player_right.bpp, &game->player_right.line_length, &game->player_right.endian);

	game->map->player->player_sprit = game->player_front;
	game->map->exit->exit_sprit = game->exit_close;
}

void	img_delete(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall.img);
	game->wall.addr = 0;
	game->wall.bpp = 0;
	game->wall.endian = 0;
	game->wall.line_length = 0;
	game->wall.heigth = 0;
	game->wall.width = 0;
	mlx_destroy_image(game->mlx, game->ground.img);
	game->ground.addr = 0;
	game->ground.bpp = 0;
	game->ground.endian = 0;
	game->ground.line_length = 0;
	game->ground.heigth = 0;
	game->ground.width = 0;
	mlx_destroy_image(game->mlx, game->item.img);
	game->item.addr = 0;
	game->item.bpp = 0;
	game->item.endian = 0;
	game->item.line_length = 0;
	game->item.heigth = 0;
	game->item.width = 0;
	mlx_destroy_image(game->mlx, game->exit_close.img);
	game->exit_close.addr = 0;
	game->exit_close.bpp = 0;
	game->exit_close.endian = 0;
	game->exit_close.line_length = 0;
	game->exit_close.heigth = 0;
	game->exit_close.width = 0;
	mlx_destroy_image(game->mlx, game->exit_open.img);
	game->exit_open.addr = 0;
	game->exit_open.bpp = 0;
	game->exit_open.endian = 0;
	game->exit_open.line_length = 0;
	game->exit_open.heigth = 0;
	game->exit_open.width = 0;
	mlx_destroy_image(game->mlx, game->player_front.img);
	game->player_front.addr = 0;
	game->player_front.bpp = 0;
	game->player_front.endian = 0;
	game->player_front.line_length = 0;
	game->player_front.heigth = 0;
	game->player_front.width = 0;
	mlx_destroy_image(game->mlx, game->player_back.img);
	game->player_back.addr = 0;
	game->player_back.bpp = 0;
	game->player_back.endian = 0;
	game->player_back.line_length = 0;
	game->player_back.heigth = 0;
	game->player_back.width = 0;
	mlx_destroy_image(game->mlx, game->player_left.img);
	game->player_left.addr = 0;
	game->player_left.bpp = 0;
	game->player_left.endian = 0;
	game->player_left.line_length = 0;
	game->player_left.heigth = 0;
	game->player_left.width = 0;
	mlx_destroy_image(game->mlx, game->player_right.img);
	game->player_right.addr = 0;
	game->player_right.bpp = 0;
	game->player_right.endian = 0;
	game->player_right.line_length = 0;
	game->player_right.heigth = 0;
	game->player_right.width = 0;
}
