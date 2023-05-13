/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:31:38 by lray              #+#    #+#             */
/*   Updated: 2023/05/13 20:09:39 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <mlx/mlx.h>

# define MAP_NAME "so_long"
# define SPRITE_SIZE 64
# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGTH 124
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define ON_KEYDOWN 2
# define ON_DESTROY 17

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		heigth;
}	t_img;

typedef struct s_player
{
	unsigned int	x;
	unsigned int	y;
	t_img			player_sprit;
}	t_player;

typedef struct s_exit
{
	unsigned int	x;
	unsigned int	y;
	t_img			exit_sprit;
}	t_exit;

typedef struct s_map
{
	char			*content;
	unsigned int	nbrs_rows;
	unsigned int	nbrs_cols;
	unsigned int	nbrs_items;
	t_player		*player;
	t_exit			*exit;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
	t_img	wall;
	t_img	ground;
	t_img	background;
	t_img	item;
	t_img	exit_close;
	t_img	exit_open;
	t_img	player_front;
	t_img	player_back;
	t_img	player_left;
	t_img	player_right;
}	t_game;

int		args_parser(int *argc, char ***argv);

int		map_parser(t_map **map, char *path);

int		map_checker(t_map *map);

int		map_init(t_map **map);
int		map_set_content(t_map *map, char *map_str);
int		map_copy(t_map *map, t_map *copy);
void	map_free(t_map *map);

int		get_cell(t_map *map, unsigned int x, unsigned int y);
int		set_cell(t_map *map, unsigned int x, unsigned int y, int d);
void	flood(t_map *map, unsigned int x, unsigned int y, int arr[2]);
void	put_error(char *msg);

void	game_init(t_game *game, t_map *map);
void	game_builder(t_game *game, t_map *map);
void	game_quit(t_game *game);

void	game_collect_item(t_game *game);
void	game_switch_exit(t_game *game);
void	game_is_ended(t_game *game);
void	game_draw_playground(t_game *game);

void	handler_closebtn(t_game *game);
void	handler_keypress(int keycode, t_game *game);
void	handler_loop(t_game *game);

void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);

void	img_load(t_game *game);
void	img_delete(t_game *game);

void	dbmap_show_format(t_map *map);
void	dbmap_show_infos(t_map *map);
void	dbgame_show_infos(t_game *game);
void	dbimg_show_infos(t_img *img);
#endif
