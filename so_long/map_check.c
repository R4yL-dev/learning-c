/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:12:06 by lray              #+#    #+#             */
/*   Updated: 2023/05/02 16:25:00 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_surrounded(t_map *map);

int	map_check(t_map *map)
{
	if (!map->is_rectangle)
	{
		put_error("The map must be rectangular");
		return (0);
	}
	if (!is_surrounded(map))
	{
		put_error("The map must be surrounded by walls");
		return (0);
	}
	return (1);
}

/*
TODO:
	Cette fonction doit vérifié que la carte est entourée par des murs (1).
	Elle doit regarder que la première et la dernière ligne ne sont que des 1.
	Toutes les autres lignes doivent se commencer et se terminer par des 1.

	Si la carte est entourée par des murs, la fonction set map->is_surrounded
	a 1 et renvoie 1.
	Sinon, elle renvoie 0;
*/
static int	is_surrounded(t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while(x < map->nbrs_cols)
	{
		if (get_cel(map, x, 0) != '1' || get_cel(map, x, map->nbrs_rows - 1) != '1')
			return (0);
		x++;
	}
	y = 1;
	while (y < map->nbrs_rows - 1)
	{
		if (get_cel(map, 0, y) != '1' || get_cel(map, map->nbrs_cols - 1, y) != '1')
			return (0);
		y++;
	}
	map->is_surrounded = 1;
	return (1);
}
