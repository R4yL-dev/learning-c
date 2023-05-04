/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:32:37 by lray              #+#    #+#             */
/*   Updated: 2023/05/03 18:39:51 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map		*map;
	map = NULL;
	if (!parse_args(&argc, &argv))
		exit (EXIT_FAILURE);
	if (!map_init(&map, argv[0]) || !map_check(map))
	{
		map_free(map);
		exit (EXIT_FAILURE);
	}
	dbmap_show_format(map);
	dbmap_show_infos(map);
	map_free(map);
	return (EXIT_SUCCESS);
}
