/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:13:39 by lray              #+#    #+#             */
/*   Updated: 2023/05/29 15:28:25 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	TODO:
		- Voici le deroulement de la simulation :
		1) Lancer les threads
		2) Lancer le superviseur (boucle infinie qui break quand un philo est mort).
		3) Quand la boucle est break, il faut que le superviseur set le status DEAD
		a tous les philos.
		4) Thread_join() afin d attendre la fin de l execution de tous les philos.
*/

void	simulation_run(t_context *ctx)
{
	printf("START SIMULATION ...\n");
	printf("START SUPERVISOR\n");
	pthread_create(&ctx->supervisor->thread, NULL, supervisor_routine, ctx);
	pthread_join(ctx->supervisor->thread, NULL);
}
