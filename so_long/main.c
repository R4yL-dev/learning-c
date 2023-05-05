/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:32:37 by lray              #+#    #+#             */
/*   Updated: 2023/05/05 18:18:34 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map		*map;
	map = NULL;
	if (!args_parser(&argc, &argv))
		exit (EXIT_FAILURE);
	if (!map_parser(&map, argv[0]) || !map_checker(map))
	{
		map_free(map);
		exit (EXIT_FAILURE);
	}
	ft_printf("OURRRRAAAAAAA\n");
	// dbmap_show_format(map);
	// dbmap_show_infos(map);
	map_free(map);
	return (EXIT_SUCCESS);
}
