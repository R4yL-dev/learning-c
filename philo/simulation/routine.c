/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:14:09 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 04:21:23 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal_time = time_get_current();
	if (philo->id % 2 == 0)
		time_sleep(philo->timing->time_to_eat / 2);
	while (1)
	{
		if (!rtn_eat(philo))
			break ;
		if (!rtn_sleep(philo))
			break ;
		if (!rtn_think(philo))
			break ;
	}
	return (NULL);
}
