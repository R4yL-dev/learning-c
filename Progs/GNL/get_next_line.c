/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 02:59:17 by lray              #+#    #+#             */
/*   Updated: 2023/02/11 03:48:13 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
static void	read_and_store(int fd, t_list **reserve);
static void	store(t_list **reserve, char *buf, int nbr_char);
static void	get_line(t_list *reserve, char **line);
static void	clean_reserve(t_list **reserve);


char	*get_next_line(int fd)
{
	static t_list	*reserve = NULL;
	char			*line;

	// init reserve et line
	line = NULL;
	// on retounr si le file descriptor n'est pas valide ou si la taille du buffer est plus petite que 1 ou si le fichier ne peu pas être lu
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	// 1) on lit et in ajoute le contenu du fichier dans la reserve tant qu'il n'y a pas de nouvelle ligne
	read_and_store(fd, &reserve);
	if (reserve == NULL)
		return (NULL);
	// 2) On extrait la ligne de la reserve
	get_line(reserve, &line);
	// 3) On nettoye la reserve
	clean_reserve(&reserve);
	if (line[0] == '\0')
	{
		free_all(reserve);
		reserve = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

static void	read_and_store(int fd, t_list **reserve)
{
	char	*buf;
	int		nbr_char_read;

	nbr_char_read = 1;
	while (!as_newline(*reserve) && nbr_char_read != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		nbr_char_read = (int)read(fd, buf, BUFFER_SIZE);
		if ((*reserve == NULL && nbr_char_read == 0) || nbr_char_read == -1)
		{
			free(buf);
			return ;
		}
		buf[nbr_char_read] = '\0';
		store(reserve, buf, nbr_char_read);
		free(buf);
	}
}

static void	store(t_list **reserve, char *buf, int nbr_char)
{
	int		i;
	t_list	*last_node;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (nbr_char + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buf[i] && i < nbr_char)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*reserve == NULL)
	{
		*reserve = new_node;
		return ;
	}
	last_node = ft_get_last(*reserve);
	last_node->next = new_node;
}

static void	get_line(t_list *reserve, char **line)
{
	int	i;
	int	j;

	if (reserve == NULL)
		return ;
	make_line(line, reserve);
	if (*line == NULL)
		return ;
	j = 0;
	while (reserve)
	{
		i = 0;
		while (reserve->content[i])
		{
			if (reserve->content[i] == '\n')
			{
				(*line)[j++] = reserve->content[i];
				break ;
			}
			(*line)[j++] = reserve->content[i++];
		}
		reserve = reserve->next;
	}
	(*line)[j] = '\0';
}

static void	clean_reserve(t_list **reserve)
{
	t_list	*last_node;
	t_list	*new_node;
	int		i;
	int		j;

	new_node = malloc(sizeof(t_list));
	if (reserve == NULL || new_node == NULL)
		return ;
	new_node->next = NULL;
	last_node = ft_get_last(*reserve);
	i = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	if (last_node->content && last_node->content[i] == '\n')
		i++;
	new_node->content = malloc(sizeof(char) * ((ft_strlen(last_node->content) - i) + 1));
	if (new_node->content == NULL)
		return ;
	j = 0;
	while (last_node->content[i])
		new_node->content[j++] = last_node->content[i++];
	new_node->content[j] = '\0';
	free_all(*reserve);
	*reserve = new_node;
}
