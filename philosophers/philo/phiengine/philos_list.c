/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:54:20 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 04:22:07 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

t_philo	*philos_list_init(int *params)
{
	t_philo	*head;
	t_philo	*prev;
	t_philo	*new;
	int		i;

	head = philo_init(1);
	head->next = head;
	if (params[0] > 1)
	{
		prev = head;
		i = 1;
		while (i < params[0])
		{
			new = philo_init(i + 1);
			if (!new)
				return (NULL);
			prev->next = new;
			prev = new;
			i++;
		}
		new->next = head;
	}
	return (head);
}

void	philos_list_show(t_philo *head)
{
	t_philo	*ptr;

	ptr = head;
	while (1)
	{
		philo_show(ptr);
		ptr = ptr->next;
		if (ptr->id == 1)
			break ;
	}
}

void	philos_list_delete(t_philo *head)
{
	t_philo	*ptr;
	t_philo	*next;
	int		nbrs_philo;

	ptr = head;
	nbrs_philo = 0;
	while (1)
	{
		nbrs_philo++;
		if (ptr->next->id == 1)
			break ;
		ptr = ptr->next;
	}
	ptr = head;
	while (nbrs_philo > 0)
	{
		next = ptr->next;
		philo_delete(ptr);
		ptr = next;
		nbrs_philo--;
	}
}
