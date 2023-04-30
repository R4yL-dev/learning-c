/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:35:37 by lray              #+#    #+#             */
/*   Updated: 2023/04/30 20:34:52 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_ber(char *path);
static int	is_valide_path(char *path);

int	parse_args(int *argc, char ***argv)
{
	(*argc)--;
	(*argv)++;
	if (*argc != 1)
	{
		put_error("The number of arguments must be 1");
		return (0);
	}
	if (!is_ber((*argv)[0]))
	{
		put_error("The extension of the card must be .ber");
		return (0);
	}
	if (!is_valide_path((*argv)[0]))
	{
		put_error("The path is not valid or the file is not readable");
		return (0);
	}
	return (1);
}

static int	is_ber(char *path)
{
	int		len;
	char	*ext;

	len = ft_strlen(path);
	if (len <= 4)
		return (0);
	ext = ft_substr(path, len - 4, 4);
	if (ft_strncmp(ext, ".ber", 4) != 0)
	{
		free(ext);
		return (0);
	}
	free(ext);
	return (1);
}

static int	is_valide_path(char *path)
{
	if (access(path, F_OK) == -1 || access(path, R_OK) == -1)
		return (0);
	return (1);
}
