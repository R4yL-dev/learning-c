/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:29:55 by lray              #+#    #+#             */
/*   Updated: 2023/05/02 15:31:17 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_cel(t_map *map, unsigned int x, unsigned int y)
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
	return (map->content[x + (y * (map->nbrs_cols))]);
}
