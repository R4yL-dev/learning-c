/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:24:21 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 04:31:55 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

long int	time_get_current(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

long int	time_get_interval(long int start, long int end)
{
	return (end - start);
}

void	time_sleep(long int ms)
{
	long int	start;
	long int	timer;

	start = time_get_current();
	timer = time_get_interval(start, time_get_current());
	while (timer < ms)
	{
		timer = time_get_interval(start, time_get_current());
		usleep(ms / 1000);
	}
}
