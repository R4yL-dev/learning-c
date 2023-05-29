/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 23:13:10 by lray              #+#    #+#             */
/*   Updated: 2023/05/21 00:09:40 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Il faudra que je mettte ce mutex dans une structure globale

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(&philo->fork->mutex);
	thread_say_take_his_fork(philo);
	pthread_mutex_lock(&philo->next->fork->mutex);
	thread_say_take_other_fork(philo);
	thread_say_start_eating(philo);
	usleep(400000);
	thread_say_stop_eating(philo);
	thread_say_down_other_fork(philo);
	pthread_mutex_unlock(&philo->next->fork->mutex);
	thread_say_down_his_fork(philo);
	pthread_mutex_unlock(&philo->fork->mutex);
	return ((void *)1);
}



void	thread_say_take_his_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->sv->mutex_print);
	printf("[T#%d]\tTake his fork\n", philo->id);
	pthread_mutex_unlock(&philo->sv->mutex_print);
}

void	thread_say_take_other_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->sv->mutex_print);
	printf("[T#%d]\tTake #%d fork\n", philo->id, philo->next->id);
	pthread_mutex_unlock(&philo->sv->mutex_print);
}

void	thread_say_down_his_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->sv->mutex_print);
	printf("[T#%d]\tPut down his fork\n", philo->id);
	pthread_mutex_unlock(&philo->sv->mutex_print);
}

void	thread_say_down_other_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->sv->mutex_print);
	printf("[T#%d]\tPut down #%d fork\n", philo->id, philo->next->id);
	pthread_mutex_unlock(&philo->sv->mutex_print);
}

void	thread_say_start_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->sv->mutex_print);
	printf("[T#%d]\tStart eating\n", philo->id);
	pthread_mutex_unlock(&philo->sv->mutex_print);
}

void	thread_say_stop_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->sv->mutex_print);
	printf("[T#%d]\tStop eating\n", philo->id);
	pthread_mutex_unlock(&philo->sv->mutex_print);
}
