/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:09:17 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 04:28:41 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

static int	set_mutex_and_timing(t_context *ctx);
static int	init_mutex(t_context *ctx);

t_context	*context_init(int *params)
{
	t_context	*ctx;

	ctx = malloc(sizeof(t_context));
	if (!ctx)
	{
		free(params);
		ft_puterror("Malloc failed");
		return (NULL);
	}
	ctx->all_philos_alive = 1;
	ctx->nbrs_philos = params[0];
	ctx->nbrs_time_eat = params[4];
	ctx->timing = timing_init(params);
	ctx->philos = philos_list_init(params);
	free(params);
	if (!set_mutex_and_timing(ctx))
		return (NULL);
	return (ctx);
}

void	context_show(t_context *ctx)
{
	printf("ctx->all_philos_alive\t:\t%d\n", ctx->all_philos_alive);
	printf("ctx->nbrs_philo\t\t:\t%d\n", ctx->nbrs_philos);
	printf("ctx->nbrs_time_eat\t:\t%d\n", ctx->nbrs_time_eat);
	timing_show(ctx->timing);
	philos_list_show(ctx->philos);
	printf("ctx->print_mutex\t:\t%p\n", &ctx->print_mutex);
}

void	context_delete(t_context *ctx)
{
	philos_list_delete(ctx->philos);
	timing_delete(ctx->timing);
	pthread_mutex_destroy(&ctx->print_mutex);
	pthread_mutex_destroy(&ctx->status_mutex);
	free(ctx);
}

static int	set_mutex_and_timing(t_context *ctx)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = ctx->philos;
	if (!init_mutex(ctx))
		return (0);
	while (i < ctx->nbrs_philos)
	{
		philo->print_mutex = &ctx->print_mutex;
		philo->status_mutex = &ctx->status_mutex;
		philo->timing = ctx->timing;
		philo = philo->next;
		i++;
	}
	return (1);
}

static int	init_mutex(t_context *ctx)
{
	if (!ctx->philos)
	{
		ft_puterror("Can't create philos");
		return (0);
	}
	if (pthread_mutex_init(&ctx->print_mutex, NULL) != 0)
	{
		ft_puterror("Mutex creation failed");
		return (0);
	}
	if (pthread_mutex_init(&ctx->status_mutex, NULL) != 0)
	{
		ft_puterror("Mutex creation failed");
		return (0);
	}
	return (1);
}
