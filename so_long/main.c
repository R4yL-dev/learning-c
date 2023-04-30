/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:32:37 by lray              #+#    #+#             */
/*   Updated: 2023/04/30 20:36:38 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_cel(t_map *map, unsigned int x, unsigned int y);

int	main(int argc, char **argv)
{
	t_map	*map;

	map = NULL;
	if (!parse_args(&argc, &argv))
		exit (EXIT_FAILURE);
	if (!map_init(&map, argv[0]))
	{
		map_free(map);
		exit (EXIT_FAILURE);
	}
	dbmap_show_format(map);
	dbmap_show_infos(map);
	get_cel(map, 18, 8);
	map_free(map);
	return (EXIT_SUCCESS);
}

static int	get_cel(t_map *map, unsigned int x, unsigned int y)
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
	ft_printf("Char x:%d y:%d -> %c\n", x, y, map->content[x + (y * (map->nbrs_cols))]);
	return (1);
}
