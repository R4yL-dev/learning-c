/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:54:20 by lray              #+#    #+#             */
/*   Updated: 2023/05/18 21:37:03 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	FIXME: Il faut que je rework le system de philo.
		Il faut que j applique la logique de la liste chainee.
		je veux faire une fonction philo_add qui prend en parametre
		la tete de la liste (premier philo) ainsi que les params du philo;


*/

t_philo	*philo_init(t_philo *philos, int id, int *params)
{
	philos->id = id;
	philos->time_to_die = params[1] * 1000;
	philos->time_to_eat = params[2] * 1000;
	philos->time_to_sleep = params[3] * 1000;
	philos->nbrs_time_eat = params[4];
	philos->thread = NULL;
	fork_init(&philos->fork);

	printf("id = %d\n", philos->id);
	printf("time_to_die = %d\n", philos->time_to_die);
	printf("time_to_eat = %d\n", philos->time_to_eat);
	printf("time_to_eat = %d\n", philos->time_to_sleep);
	printf("nbrs_time_eat = %d\n", philos->nbrs_time_eat);
	printf("Thread = %p\n", philos->thread);
	return (philos);
}

void	philo_add(t_philo *head, int *params)
{
	(void) params;
	if (head == NULL)
	{
		printf("COUCOU\n");
	}
}
