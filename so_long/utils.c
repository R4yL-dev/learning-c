/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:29:55 by lray              #+#    #+#             */
/*   Updated: 2023/05/03 15:13:55 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_cell(t_map *map, unsigned int x, unsigned int y)
{
	if (x >= map->nbrs_cols)
	{
		put_error("x must not be greater than the number of colonnes");
		return (0);
	}
	if (y >= map->nbrs_rows)
	{
		put_error("y must not be greater than the number of rows");
		return (0);
	}
	return (map->content[x + (y * map->nbrs_cols)]);
}

int	set_cell(t_map *map, unsigned int x, unsigned int y, int d)
{
	if (x >= map->nbrs_cols)
	{
		put_error("x must not be greater than the number of colonnes");
		return (0);
	}
	if (y >= map->nbrs_rows)
	{
		put_error("y must not be greater than the number of rows");
		return (0);
	}
	if (d != '0' && d != '1' && d != 'P' && d != 'E' && d != 'C')
	{
		put_error("The new value of the cell must be 0, 1, P, E or C");
		return (0);
	}
	map->content[x + (y * map->nbrs_cols)] = d;
	return (1);
}
