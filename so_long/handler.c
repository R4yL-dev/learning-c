/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:32:32 by lray              #+#    #+#             */
/*   Updated: 2023/05/13 20:02:28 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handler_closebtn(t_game *game)
{
	game_quit(game);
}

void	handler_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		game_quit(game);
	if (keycode == KEY_UP || keycode == KEY_W)
		move_up(game);
	if (keycode == KEY_LEFT || keycode == KEY_A)
		move_left(game);
	if (keycode == KEY_DOWN || keycode == KEY_S)
		move_down(game);
	if (keycode == KEY_RIGTH || keycode == KEY_D)
		move_right(game);
}

void	handler_loop(t_game *game)
{
	game_collect_item(game);
	game_switch_exit(game);
	game_is_ended(game);
	game_draw_playground(game);
}
