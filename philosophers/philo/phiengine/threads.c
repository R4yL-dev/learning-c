/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:07:10 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 20:11:03 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	threads_start(t_context *ctx)
{
	t_philo	*philo;
	int		i;

	philo = ctx->philos;
	i = 0;
	if (ctx->nbrs_philos == 1)
		pthread_create(&philo->thread, NULL, routine_solo, philo);
	else
	{
		while (i < ctx->nbrs_philos)
		{
			pthread_create(&philo->thread, NULL, routine, philo);
			philo = philo->next;
			i++;
		}
	}
}

void	threads_wait(t_context *ctx)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = ctx->philos;
	while (i < ctx->nbrs_philos)
	{
		pthread_join(philo->thread, NULL);
		philo = philo->next;
		i++;
	}
}
