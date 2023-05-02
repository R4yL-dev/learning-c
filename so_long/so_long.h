/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:31:38 by lray              #+#    #+#             */
/*   Updated: 2023/05/02 15:31:46 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

typedef struct s_map
{
	char			*content;
	unsigned int	nbrs_rows;
	unsigned int	nbrs_cols;
	unsigned int	is_rectangle;
	unsigned int	is_surrounded;
}	t_map;

/*Parse arguments.*/
int		parse_args(int *argc, char ***argv);

/*Initialize map with file in path.*/
int	map_init(t_map **map, char *path);
/*Clean map*/
void	map_free(t_map *map);

int		map_check(t_map *map);

int		get_cel(t_map *map, unsigned int x, unsigned int y);

/*Show error message on stderr.*/
void	put_error(char *msg);

/*Show the formatted map.*/
void	dbmap_show_format(t_map *map);
/*Show all infos about the map.*/
void	dbmap_show_infos(t_map *map);

#endif
