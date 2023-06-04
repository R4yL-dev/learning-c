/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_solo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:09:37 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 19:53:43 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	*routine_solo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	take_first_fork(philo);
	time_sleep(philo->timing->time_to_die);
	pthread_mutex_lock(philo->status_mutex);
	philo->status = DEAD;
	pthread_mutex_unlock(philo->status_mutex);
	philo_talk(philo, "died");
	put_down_first_fork(philo);
	return (NULL);
}
