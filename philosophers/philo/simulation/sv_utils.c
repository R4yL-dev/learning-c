/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sv_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:48:55 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 18:54:37 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	kill_all_philos(t_context *ctx)
{
	t_philo	*philo;
	int		i;

	philo = ctx->philos;
	i = 0;
	while (i < ctx->nbrs_philos)
	{
		pthread_mutex_lock(philo->status_mutex);
		philo->status = DEAD;
		pthread_mutex_unlock(philo->status_mutex);
		philo = philo->next;
		i++;
	}
}

int	have_eat_enough(t_context *ctx, t_philo *philo)
{
	int	res;

	pthread_mutex_lock(&ctx->nbrs_meal_mutex);
	res = philo->nbrs_time_eat;
	pthread_mutex_unlock(&ctx->nbrs_meal_mutex);
	if (ctx->nbrs_time_eat > 0 && res >= ctx->nbrs_time_eat)
		return (1);
	return (0);
}

int	have_everybody_eat_enough(t_context *ctx)
{
	t_philo	*philo;
	int		i;
	int		res;

	philo = ctx->philos;
	i = 0;
	res = 0;
	while (i < ctx->nbrs_philos)
	{
		pthread_mutex_lock(&ctx->nbrs_meal_mutex);
		if (philo->nbrs_time_eat >= ctx->nbrs_time_eat)
			res++;
		pthread_mutex_unlock(&ctx->nbrs_meal_mutex);
		philo = philo->next;
		i++;
	}
	if (res == ctx->nbrs_philos)
		return (1);
	return (0);
}
