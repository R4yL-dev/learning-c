/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 17:04:36 by lray              #+#    #+#             */
/*   Updated: 2023/05/07 23:40:54 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	open_file(int *fd, char *path);
static int	read_file(t_map *map, int *fd, char **buf);
static void	extract_nl(char **line, char **tmp_line);
static int	wrapper_norm(char **buf);

int	map_parser(t_map **map, char *path)
{
	int		fd;
	char	*buf;

	buf = "";
	if (!map_init(map) || !open_file(&fd, path))
		return (0);
	if (!read_file((*map), &fd, &buf))
	{
		free(buf);
		close(fd);
		put_error("The map must be rectangular");
		return (0);
	}
	close(fd);
	if (!wrapper_norm(&buf))
		return (0);
	if (!map_set_content((*map), buf))
	{
		free(buf);
		return (0);
	}
	free(buf);
	return (1);
}

static int	open_file(int *fd, char *path)
{
	*fd = open(path, O_RDONLY);
	if (*fd == -1)
	{
		put_error("Open failed");
		return (0);
	}
	return (1);
}

static int	read_file(t_map *map, int *fd, char **buf)
{
	char	*line;
	char	*tmp_line;
	char	*tmp_buf;
	int		resp;

	resp = 1;
	while (1)
	{
		line = get_next_line(*fd);
		if (!line)
			break ;
		map->nbrs_rows++;
		extract_nl(&line, &tmp_line);
		if (map->nbrs_cols == 0)
			map->nbrs_cols = ft_strlen(tmp_line);
		if (ft_strlen(tmp_line) != map->nbrs_cols)
			resp = 0;
		tmp_buf = ft_strdup(*buf);
		if (ft_strncmp(*buf, "", 1))
			free(*buf);
		*buf = ft_strjoin(tmp_buf, tmp_line);
		free(tmp_buf);
		free(tmp_line);
	}
	return (resp);
}

static void	extract_nl(char **line, char **tmp_line)
{
	*tmp_line = ft_strtrim(*line, "\n");
	free(*line);
}

static int	wrapper_norm(char **buf)
{
	if (!ft_strncmp(*buf, "", 1))
	{
		put_error("The file is empty");
		return (0);
	}
	return (1);
}
