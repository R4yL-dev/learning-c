/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:24:24 by lray              #+#    #+#             */
/*   Updated: 2022/11/15 22:21:49 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Desc :
		Write a fucntion that returns a line read from a file descriptor.

	Params :
		- fd : The file descriptor to read from.

	Ret :
		Read line if correct behavior.
		NULL of there is nothing else to read, or an error occurred.
*/

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

void	read_and_store(int fd, char *reserve);

char	*get_next_line(int fd)
{
	static char		*reserve;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	reserve = NULL;
	//1) read from fd and add to reserve
	//2) make line from reserve
	//3) clean reserve
	read_and_store(fd, reserve);

	return (line);
}

void	read_and_store(int fd, char *reserve)
{
	char	*buf;
	int		size_read;

	size_read = 1;
	while (!has_newline(reserve) && size_read != 0)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		size_read = read(fd, buf, BUFFER_SIZE);
		if ((!reserve && size_read == 0) || size_read == -1)
		{
			free(buf);
			return ;
		}
		buf[size_read] = '\0';

	}
	//Parcourir la reservce tant que \n n'est pas trouver ou que nous ne somme pas en fin de fichier
	//	Allocation du buffer (BUFFER_SIZE + 1 pour le \0)
	//	Ont met le fd dans le buffer
	//	Si la reserve est NULL && size_read est 0 ou que size_read est -1
	//		On free le buffer et on retourn
	//	Ont ajoute \0 à la fin du buffer
	//	On ajoute le buffer dans la reserve
	// On free le buffer
}

void	make_line()
{

}

void	clean_reserve()
{

}


