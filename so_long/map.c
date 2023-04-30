/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:04:36 by lray              #+#    #+#             */
/*   Updated: 2023/04/30 20:29:38 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*map_read(t_map *map, char *path);
static int	map_load(t_map *map, char *map_str);

int	map_init(t_map **map, char *path)
{
	char	*map_str;

	(*map) = malloc(sizeof(t_map));
	if (!map)
	{
		put_error("Malloc failed");
		return (0);
	}
	(*map)->content = NULL;
	(*map)->nbrs_cols = 0;
	(*map)->nbrs_rows = 0;
	map_str = map_read((*map), path);
	if (!map_str)
		return (0);
	if (!map_load((*map), map_str))
	{
		free(map_str);
		return (0);
	}
	free(map_str);
	return (1);
}

/*
Read map from path.
Set nbrs_rows and nbrs_cols.
Return map in a string.
*/
static char	*map_read(t_map *map, char *path)
{
	int		fd;
	char	*line;
	char	*tmp_line;
	char	*buf;
	char	*tmp_buf;

	buf = "";
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		put_error("Open failed");
		return (NULL);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->nbrs_rows++;
		tmp_line = ft_strtrim(line, "\n");
		map->nbrs_cols = ft_strlen(tmp_line);
		free(line);
		tmp_buf = ft_strdup(buf);
		if (ft_strncmp(buf, "", 1))
			free(buf);
		buf = ft_strjoin(tmp_buf, tmp_line);
		free(tmp_buf);
		free(tmp_line);
	}
	close(fd);
	if (!ft_strncmp(buf, "", 1))
	{
		put_error("The file is empty");
		return (NULL);
	}
	return (buf);
}

/*
Initialize map content with the map in string.
*/
static int	map_load(t_map *map, char *map_str)
{
	ft_printf("\n");
	map->content = malloc(sizeof(char) * (ft_strlen(map_str) + 1));
	if (!map->content)
	{
		put_error("Malloc failed");
		return (0);
	}
	ft_strlcpy(map->content, map_str, ft_strlen(map_str) + 1);
	return (1);
}

void	map_free(t_map *map)
{
	if (map)
	{
		if (map->content)
			free(map->content);
		free(map);
		map = NULL;
	}
}
