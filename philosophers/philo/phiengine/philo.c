/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 01:57:26 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 18:47:32 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

t_philo	*philo_init(int id)
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
	new->last_meal_time = 0;
	if (pthread_mutex_init(&new->fork, NULL) != 0)
	{
		ft_puterror("Mutex creation failed");
		return (NULL);
	}
	new->thread = 0;
	new->next = NULL;
	return (new);
}

void	philo_talk(t_philo *philo, char *msg)
{
	long int	start;

	start = philo->timing->start;
	pthread_mutex_lock(philo->print_mutex);
	printf("[%ldms]   \t", time_get_interval(start, time_get_current()));
	printf("Philo n° %d\t", philo->id);
	printf("%s\n", msg);
	pthread_mutex_unlock(philo->print_mutex);
}

void	philo_show(t_philo *philo)
{
	printf("philo->id\t\t:\t%d\n", philo->id);
	printf("philo->status\t\t:\t%d\n", philo->status);
	printf("philo->nbrs_time_eat\t:\t%d\n", philo->nbrs_time_eat);
	timing_show(philo->timing);
	printf("philo->fork\t\t:\t%p\n", &philo->fork);
	printf("philo->thread\t\t:\t%p\n", &philo->thread);
	printf("philo->print_mutex\t:\t%p\n", philo->print_mutex);
	printf("philo->next\t\t:\t%p\n", philo->next);
}

void	philo_delete(t_philo *philo)
{
	pthread_mutex_destroy(&philo->fork);
	philo->next = NULL;
	free(philo);
}
