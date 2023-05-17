/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:38:17 by lray              #+#    #+#             */
/*   Updated: 2023/05/17 19:52:05 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *routine()
{
	printf("STRT OF THREAD\n");
	usleep(5000000);
	printf("END OF THREAD\n");
	return (NULL);
}

int	main()
{
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
	return (0);
}
