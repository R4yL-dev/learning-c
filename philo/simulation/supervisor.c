/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:10:33 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 02:50:09 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static void	kill_all_philos(t_context *ctx);

void	supervisor_run(t_context *ctx)
{
	t_philo		*philo;
	int			status;

	philo = ctx->philos;
	while (1)
	{
		pthread_mutex_lock(&ctx->status_mutex);
		status = philo->status;
		pthread_mutex_unlock(&ctx->status_mutex);
		if (status == DEAD)
		{
			pthread_mutex_lock(&ctx->status_mutex);
			kill_all_philos(ctx);
			pthread_mutex_unlock(&ctx->status_mutex);
			break ;
		}
		philo = philo->next;
	}
}

static void	kill_all_philos(t_context *ctx)
{
	t_philo	*philo;
	int		i;

	philo = ctx->philos;
	i = 0;
	while (i < ctx->nbrs_philos)
	{
		philo->status = DEAD;
		philo = philo->next;
		i++;
	}
}
