/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:47:47 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 02:49:48 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

t_timing	*timing_init(int *params)
{
	t_timing	*new;

	new = malloc(sizeof(t_timing));
	if (!new)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	new->time_to_die = params[1];
	new->time_to_eat = params[2];
	new->time_to_sleep = params[3];
	new->start = 0;
	return (new);
}

void	timing_show(t_timing *timing)
{
	printf("timing->time_to_die\t:\t%d\n", timing->time_to_die);
	printf("timing->time_to_eat\t:\t%d\n", timing->time_to_eat);
	printf("timing->time_to_sleep\t:\t%d\n", timing->time_to_sleep);
	printf("timing->start\t\t:\t%ld\n", timing->start);
}

void	timing_delete(t_timing *timing)
{
	free(timing);
}
