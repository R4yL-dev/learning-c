/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:31:38 by lray              #+#    #+#             */
/*   Updated: 2023/05/06 17:53:45 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

typedef struct s_player
{
	unsigned int	x;
	unsigned int	y;
}	t_player;

typedef struct s_exit
{
	unsigned int	x;
	unsigned int	y;
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

void	dbmap_show_format(t_map *map);
void	dbmap_show_infos(t_map *map);
#endif
