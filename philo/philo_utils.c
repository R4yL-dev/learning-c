/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:57:26 by lray              #+#    #+#             */
/*   Updated: 2023/05/19 22:40:07 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philo_new(void)
{
	t_philo	*new;

	new = (t_philo *)malloc(sizeof(t_philo) * 1);
	if (!new)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	new->id = 0;
	new->time_to_die = 0;
	new->time_to_eat = 0;
	new->time_to_sleep = 0;
	new->nbrs_time_eat = 0;
	new->thread = 0;
	new->fork = fork_new();
	new->next = NULL;
	return (new);
}

void	philo_set(t_philo *philo, int *params, int id)
{
	philo->id = id;
	philo->time_to_die = params[1] * 1000;
	philo->time_to_eat = params[2] * 1000;
	philo->time_to_sleep = params[3] * 1000;
	philo->nbrs_time_eat = params[4];
}

t_philo	*philo_delete(t_philo **philo)
{
	t_philo	*next;

	next = (*philo)->next;
	fork_delete(&(*philo)->fork);
	free((*philo)->fork);
	free((*philo));
	return (next);
}
