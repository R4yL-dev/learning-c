/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:10:33 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 18:54:14 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static void	supervisor_signals_the_end(t_context *ctx);

void	supervisor_run(t_context *ctx)
{
	t_philo		*philo;

	philo = ctx->philos;
	while (1)
	{
		if (!is_alive(philo))
		{
			kill_all_philos(ctx);
			break ;
		}
		if (have_eat_enough(ctx, philo))
		{
			if (have_everybody_eat_enough(ctx))
			{
				kill_all_philos(ctx);
				supervisor_signals_the_end(ctx);
				break ;
			}
		}
		philo = philo->next;
	}
}

static void	supervisor_signals_the_end(t_context *ctx)
{
	long int	start;
	int			nbrs_meal;

	start = ctx->timing->start;
	nbrs_meal = ctx->nbrs_time_eat;
	pthread_mutex_lock(&ctx->print_mutex);
	printf("[%ldms]   \t", time_get_interval(start, time_get_current()));
	printf("Supervisor\t");
	printf("All philosophers have eaten at least %d time(s)\n", nbrs_meal);
	pthread_mutex_unlock(&ctx->print_mutex);
}
