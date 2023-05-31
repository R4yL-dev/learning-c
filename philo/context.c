/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   context.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:09:17 by lray              #+#    #+#             */
/*   Updated: 2023/05/21 00:36:11 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_context	*context_init(int *params)
{
	t_context *ctx;

	ctx = malloc(sizeof(t_context));
	if (!ctx)
	{
		ft_puterror("Malloc failed");
		return NULL;
	}
	ctx->nbrs_philos = params[0];
	ctx->supervisor = supervisor_init();
	if (!ctx->supervisor)
	{
		ft_puterror("Can't create supervisor\n");
		return (NULL);
	}
	ctx->philos = philos_init(ctx, params);
	if (!ctx->philos)
	{
		ft_puterror("Can't create philos");
		return (NULL);
	}
	return (ctx);
}
