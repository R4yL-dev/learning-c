/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:12:56 by lray              #+#    #+#             */
/*   Updated: 2023/04/28 17:16:32 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	open_files(int *file1, int *file2, char **argv);
static void	child_process(char *cmd, char **envp, int in_fd, int out_fd);
static void	make_dup(int *in_fd, int *out_fd, char **cmd_args, char *path);
static void	wait_close(pid_t *pid1, pid_t *pid2, int *file1, int *file2);

int	main(int argc, char **argv, char **envp)
{
	int		file1;
	int		file2;
	int		pipes[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		exit_error(errno, "Invalid number of arguments");
	open_files(&file1, &file2, argv);
	if (pipe(pipes) == -1)
		exit_error(errno, "Failed to create pipe");
	pid1 = fork();
	if (pid1 == -1)
		exit_error(errno, "Failed to fork");
	else if (pid1 == 0)
		child_process(argv[CMD1_POS], envp, file1, pipes[1]);
	close(pipes[1]);
	pid2 = fork();
	if (pid2 == -1)
		exit_error(errno, "Failed to fork");
	else if (pid2 == 0)
		child_process(argv[CMD2_POS], envp, pipes[0], file2);
	close(pipes[0]);
	wait_close(&pid1, &pid2, &file1, &file2);
	return (EXIT_SUCCESS);
}

static void	open_files(int *file1, int *file2, char **argv)
{
	*file1 = open(argv[FILE1_POS], O_RDONLY);
	if (*file1 == -1)
		exit_error(errno, "Failed to open file 1");
	*file2 = open(argv[FILE2_POS], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (*file2 == -1)
		exit_error(errno, "Failed to open file 2");
}

static void	child_process(char *cmd, char **envp, int in_fd, int out_fd)
{
	char	**cmd_args;
	char	*path;

	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		exit_error(errno, "Failed to split command");
	path = has_cmd(cmd_args[0], envp);
	if (!path)
	{
		free_array(cmd_args);
		exit_error(errno, "Command not found");
	}
	make_dup(&in_fd, &out_fd, cmd_args, path);
	close(in_fd);
	close(out_fd);
	execve(path, cmd_args, envp);
	exit_error(errno, "Failed to execute command");
}

static void	make_dup(int *in_fd, int *out_fd, char **cmd_args, char *path)
{
	if (dup2(*in_fd, STDIN_FILENO) == -1)
	{
		free_array(cmd_args);
		free(path);
		exit_error(errno, "Failed to dup2");
	}
	if (dup2(*out_fd, STDOUT_FILENO) == -1)
	{
		free_array(cmd_args);
		free(path);
		exit_error(errno, "Failed to dup2");
	}
}

static void	wait_close(pid_t *pid1, pid_t *pid2, int *file1, int *file2)
{
	waitpid(*pid1, NULL, 0);
	waitpid(*pid2, NULL, 0);
	close(*file1);
	close(*file2);
}
