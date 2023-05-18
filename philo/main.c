/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:38:17 by lray              #+#    #+#             */
/*   Updated: 2023/05/18 21:36:21 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine()
{
	printf("STRT OF THREAD\n");
	usleep(500000);
	printf("END OF THREAD\n");
	return (NULL);
}

/* void *routine()
{
	printf("Coucou\n");
	return (NULL);
} */

int	main(int argc, char **argv)
{
	/*
		2) init struct (philo, fork)
		3) start thread for eatch philo
		4) wait till end (death of a philo)
	*/
	int	*args;
	t_philo *philos;
	int		i;

	args = malloc(sizeof(int) * 5);
	if (!args)
	{
		ft_puterror("Malloc failed");
		return (1);
	}
	if (!args_parser(&argc, &argv, args))
		return (1);
	philos = NULL;
	i = 0;
	while (i < args[0])
	{
		philo_add(philos, args);
		//philo_init(&philos, i, args, last_philo);
		i++;
	}
	free(args);
	//pthread_create(philos->thread, NULL, routine, NULL);
	//printf("-- %ld\n", philos->fork.mutex.__sig);
	//pthread_join(philos->thread, NULL);
	return (0);
}

/*

	pthread_t	threads[NBRS_THREAD];
	int			i = 0;

	i = 0;
	while (i < NBRS_THREAD)
	{
		if (pthread_create(&threads[i], NULL, routine, NULL))
		{
			printf("Error when creating Thread\n");
			return (1);
		}
		printf("Creation Thread : %d\n", i);
		i++;
	}
	i = 0;
	while (i < NBRS_THREAD)
	{
		if (pthread_join(threads[i], NULL))
		{
			printf("Error when joigning thread\n");
			return (2);
		}
		i++;
	}

*/
