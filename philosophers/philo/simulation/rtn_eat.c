/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtn_eat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 03:12:37 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 17:52:21 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static int	take_both_fork(t_philo *philo);

int	rtn_eat(t_philo *philo)
{
	if (!is_alive(philo))
		return (0);
	if (!take_both_fork(philo))
		return (0);
	philo_talk(philo, "is eating");
	if (!will_survive(philo, philo->timing->time_to_eat))
	{
		put_down_both_fork(philo);
		calculate_sleep(philo);
		return (0);
	}
	else
	{
		time_sleep(philo->timing->time_to_eat);
		philo->last_meal_time = time_get_current();
	}
	put_down_both_fork(philo);
	pthread_mutex_lock(philo->nbrs_meal_mutex);
	philo->nbrs_time_eat += 1;
	pthread_mutex_unlock(philo->nbrs_meal_mutex);
	return (1);
}

static int	take_both_fork(t_philo *philo)
{
	take_first_fork(philo);
	if (!is_alive(philo))
	{
		put_down_first_fork(philo);
		return (0);
	}
	take_second_fork(philo);
	if (!is_alive(philo))
	{
		put_down_both_fork(philo);
		return (0);
	}
	return (1);
}
