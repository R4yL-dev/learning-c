/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:47:47 by lray              #+#    #+#             */
/*   Updated: 2023/06/01 16:37:35 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
TODO:
	- Quand j aurais commenceé la simulation, il faudra que je change l 'init.
	Pour le moment, je cette lors de l init le start time. Une fois que le simu
	sera en place, il faudra init a 0 et set start quand la simu débute.
*/

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
	new->start = time_get_current();
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
