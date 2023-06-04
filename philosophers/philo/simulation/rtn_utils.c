/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtn_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 03:28:17 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 04:15:26 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	is_alive(t_philo *philo)
{
	pthread_mutex_lock(philo->status_mutex);
	if (philo->status == DEAD)
	{
		pthread_mutex_unlock(philo->status_mutex);
		return (0);
	}
	pthread_mutex_unlock(philo->status_mutex);
	return (1);
}

int	will_survive(t_philo *philo, int time_to_test)
{
	int long	last_meal;
	int			time_to_die;

	last_meal = philo->last_meal_time;
	time_to_die = philo->timing->time_to_die;
	if (time_get_interval(last_meal, \
		time_get_current() + time_to_test) > time_to_die)
		return (0);
	return (1);
}

void	calculate_sleep(t_philo *philo)
{
	time_sleep(philo->timing->time_to_die - \
		time_get_interval(philo->last_meal_time, time_get_current()));
	pthread_mutex_lock(philo->status_mutex);
	philo->status = DEAD;
	pthread_mutex_unlock(philo->status_mutex);
	philo_talk(philo, "died");
}
