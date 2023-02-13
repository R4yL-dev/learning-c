/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 03:21:53 by lray              #+#    #+#             */
/*   Updated: 2023/02/13 12:01:25 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		as_newline(t_list *reserve);
t_list	*ft_get_last(t_list *reserve);
void	make_line(char **line, t_list *reserve);
int		ft_strlen(const char *str);
void	free_all(t_list *reserve);

int	as_newline(t_list *reserve)
{
	int		i;
	t_list	*current;

	if (reserve == NULL)
		return (0);
	current = ft_get_last(reserve);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*ft_get_last(t_list *reserve)
{
	t_list	*current;

	current = reserve;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	make_line(char **line, t_list *reserve)
{
	int	i;
	int	j;

	j = 0;
	while (reserve)
	{
		i = 0;
		while (reserve->content[i])
		{
			if (reserve->content[i] == '\n')
			{
				j++;
				break ;
			}
			j++;
			i++;
		}
		reserve = reserve->next;
	}
	*line = malloc(sizeof(char) * (j + 1));
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_all(t_list *reserve)
{
	t_list	*current_node;
	t_list	*next_node;

	current_node = reserve;
	while (current_node)
	{
		free(current_node->content);
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}
