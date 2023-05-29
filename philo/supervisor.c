/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:18:32 by lray              #+#    #+#             */
/*   Updated: 2023/05/29 15:20:20 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	TODO:
		- Il faut que je reface completement le fonctionnement du superviseur.
		Le superviseur ne sera plus un thread a par avec sa propre routine.
		Il faut qu il soit une boucle infine dans le thread principal.
		Dans la boucle infine, il verifie le statue de toutue les philo en
		permanance et decide si oui ou non il doit aretter la simu.

		L appel du superviseur dois se faire une fois que les thread des philos
		ont ete lancer et avant de de faire le thread_join().
*/

void	*supervisor_routine(void *arg)
{
	t_context	*ctx;

	ctx = arg;
	philos_run(ctx);
	return (NULL);
}

t_supervisor *supervisor_init()
{
	t_supervisor *sv;

	sv = malloc(sizeof(t_supervisor));
	if (!sv)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	sv->is_a_philo_dead = 0;
	sv->thread = 0;
	if (pthread_mutex_init(&sv->mutex_print, NULL) != 0)
	{
		ft_puterror("Mutex creation failed");
		return (NULL);
	}
	return (sv);
}
