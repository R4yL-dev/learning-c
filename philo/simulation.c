/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:13:39 by lray              #+#    #+#             */
/*   Updated: 2023/05/21 01:18:12 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	simulation_run(t_context *ctx)
{
	printf("START SIMULATION ...\n");
	printf("START SUPERVISOR\n");
	pthread_create(&ctx->supervisor->thread, NULL, supervisor_routine, ctx);
	pthread_join(ctx->supervisor->thread, NULL);
}
