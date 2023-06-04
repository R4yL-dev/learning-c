/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:41:51 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 02:50:04 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

void	simu_run(t_context *ctx)
{
	ctx->timing->start = time_get_current();
	threads_start(ctx);
	supervisor_run(ctx);
	threads_wait(ctx);
}
