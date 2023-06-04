/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtn_sleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 03:17:12 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 04:08:42 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int	rtn_sleep(t_philo *philo)
{
	if (!is_alive(philo))
		return (0);
	philo_talk(philo, "is sleeping");
	if (!will_survive(philo, philo->timing->time_to_sleep))
	{
		calculate_sleep(philo);
		return (0);
	}
	else
	{
		time_sleep(philo->timing->time_to_sleep);
		if (!is_alive(philo))
			return (0);
	}
	return (1);
}
