/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:57:26 by lray              #+#    #+#             */
/*   Updated: 2023/05/31 17:03:32 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philo_init(int id, int *params)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	new->id = id;
	new->status = 0;
	new->nbrs_time_eat = 0;
	new->timing = timing_init(params);
	if (pthread_mutex_init(&new->fork, NULL) != 0)
	{
		ft_puterror("Mutex creation failed");
		return (NULL);
	}
	new->thread = 0;
	new->next = NULL;
	return (new);
}

void	philo_show(t_philo *philo)
{
	printf("philo->id\t\t:\t%d\n", philo->id);
	printf("philo->status\t\t:\t%d\n", philo->status);
	printf("philo->nbrs_time_eat\t:\t%d\n", philo->nbrs_time_eat);
	timing_show(philo->timing);
	printf("philo->fork\t\t:\t%p\n", &philo->fork);
	printf("philo->thread\t\t:\t%p\n", &philo->thread);
	printf("philo->next\t\t:\t%p\n", philo->next);
}

void	philo_delete(t_philo *philo)
{
	timing_delete(philo->timing);
	pthread_mutex_destroy(&philo->fork);
	philo->next = NULL;
	free(philo);
}
