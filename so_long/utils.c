/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:29:55 by lray              #+#    #+#             */
/*   Updated: 2023/05/12 15:33:57 by lray             ###   ########.fr       */
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

void	flood(t_map *map, unsigned int x, unsigned int y, int arr[2])
{
	int	item;

	item = get_cell(map, x, y);
	if ((!arr[0] && !arr[1]) || item == '1')
		return ;
	if (item == 'C')
	{
		arr[1]--;
		set_cell(map, x, y, '1');
	}
	if (x == map->exit->x && y == map->exit->y)
		arr[0] = 0;
	if (item == '0')
		set_cell(map, x, y, '1');
	flood(map, x + 1, y, arr);
	flood(map, x - 1, y, arr);
	flood(map, x, y + 1, arr);
	flood(map, x, y - 1, arr);
}

void	put_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
}
