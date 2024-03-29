/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:13:21 by lray              #+#    #+#             */
/*   Updated: 2023/04/23 20:40:28 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"

# define CMD1_POS 2
# define CMD2_POS 3
# define FILE1_POS 1
# define FILE2_POS 4

char	*has_cmd(char *cmd, char **envp);
void	exit_error(int err, char *msg);
void	free_array(char **arr);

#endif
