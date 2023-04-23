/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:21:02 by lray              #+#    #+#             */
/*   Updated: 2023/04/23 20:45:34 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_paths(char **envp);
static void	put_error(char *str);

char	*has_cmd(char *cmd, char **envp)
{
	char	**paths;
	char	*tmp;
	char	*resp;
	int		i;

	paths = get_paths(envp);
	resp = NULL;
	i = 0;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], cmd);
		if (access(paths[i], F_OK) != -1 && access(paths[i], X_OK) != -1)
		{
			if (resp)
				free(resp);
			resp = ft_strdup(paths[i]);
		}
		free(paths[i]);
		free(tmp);
		i++;
	}
	free(paths);
	return (resp);
}

static char	**get_paths(char **envp)
{
	char	**resp;
	char	*tmp;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			resp = ft_split(envp[i], ':');
		i++;
	}
	tmp = resp[0];
	resp[0] = ft_strtrim(resp[0], "PATH=");
	free(tmp);
	i = 0;
	while (resp[i])
	{
		tmp = resp[i];
		resp[i] = ft_strjoin(resp[i], "/");
		i++;
		free(tmp);
	}
	return (resp);
}

void	exit_error(int err, char *msg)
{
	if (err == 0)
		put_error(msg);
	else
	{
		put_error(msg);
		put_error(": ");
		put_error(strerror(err));
	}
	put_error("\n");
	exit(EXIT_FAILURE);
}

static void	put_error(char *str)
{
	write(2, str, ft_strlen(str));
}

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
