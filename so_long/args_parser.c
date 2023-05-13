/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 17:35:37 by lray              #+#    #+#             */
/*   Updated: 2023/05/14 01:30:30 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_ber(char *path);

int	args_parser(int *argc, char ***argv)
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
		put_error("The extension of the map must be .ber");
		return (0);
	}
	return (1);
}

static int	is_ber(char *path)
{
	int		len;
	char	*ext;
	int		resp;

	resp = 1;
	len = ft_strlen(path);
	if (len <= 4)
		return (0);
	ext = ft_substr(path, len - 4, 4);
	if (ft_strncmp(ext, ".ber", 4) != 0)
		resp = 0;
	free(ext);
	return (resp);
}
