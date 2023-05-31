/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:09:17 by lray              #+#    #+#             */
/*   Updated: 2023/05/31 18:43:47 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_context	*context_init(int *params)
{
	t_context *ctx;

	ctx = malloc(sizeof(t_context));
	if (!ctx)
	{
		free(params);
		ft_puterror("Malloc failed");
		return NULL;
	}
	ctx->all_philos_alive = 1;
	ctx->nbrs_philos = params[0];
	ctx->nbrs_time_eat = params[4];
	ctx->philos = philos_list_init(params);
	free(params);
	if (!ctx->philos)
	{
		ft_puterror("Can't create philos");
		return (NULL);
	}
	return (ctx);
}

void	context_show(t_context *ctx)
{
	printf("ctx->all_philos_alive\t:\t%d\n", ctx->all_philos_alive);
	printf("ctx->nbrs_philo\t\t:\t%d\n", ctx->nbrs_philos);
	printf("ctx->nbrs_time_eat\t:\t%d\n", ctx->nbrs_time_eat);
	philos_list_show(ctx->philos);
}

void	context_delete(t_context *ctx)
{
	philos_list_delete(ctx->philos);
	free(ctx);
}
