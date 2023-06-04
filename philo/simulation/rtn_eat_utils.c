/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtn_eat_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 03:23:03 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 04:11:04 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	take_first_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&philo->fork);
	else
		pthread_mutex_lock(&philo->next->fork);
	philo_talk(philo, "has taken a fork");
}

void	take_second_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&philo->next->fork);
	else
		pthread_mutex_lock(&philo->fork);
	philo_talk(philo, "has taken a fork");
}

void	put_down_first_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_unlock(&philo->fork);
	else
		pthread_mutex_unlock(&philo->next->fork);
}

void	put_down_second_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_unlock(&philo->next->fork);
	else
		pthread_mutex_unlock(&philo->fork);
}

void	put_down_both_fork(t_philo *philo)
{
	put_down_first_fork(philo);
	put_down_second_fork(philo);
}
