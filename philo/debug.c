/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 00:27:36 by lray              #+#    #+#             */
/*   Updated: 2023/05/21 00:49:03 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dbcontext(t_context *ctx)
{
	printf("\nctx->time_start\t\t\t:\t%ld\n", ctx->time_start.tv_sec);
	printf("ctx->nbrs_philo\t\t\t:\t%d\n", ctx->nbrs_philos);
	dbsupervisor(ctx->supervisor);
	dbphilos(ctx->philos);
}

void	dbsupervisor(t_supervisor *sv)
{
	printf("\nsupervisor->is_a_philo_dead\t:\t%d\n", sv->is_a_philo_dead);
	printf("supervisor->thread\t\t:\t%p\n", &sv->thread);
	printf("supervisor->mutex\t\t:\t%p\n", &sv->mutex_print);
}

void	dbphilos(t_philo *head)
{
	t_philo	*ptr;

	ptr = head;
	while (1)
	{
		dbphilo(ptr);
		ptr = ptr->next;
		if (ptr->id == 1)
			break ;
	}
}

void	dbphilo(t_philo *philo)
{
	printf("\n");
	printf("philo->id\t\t\t:\t%d\n", philo->id);
	printf("philo->time_to_die\t\t:\t%d\n", philo->time_to_die);
	printf("philo->time_to_eat\t\t:\t%d\n", philo->time_to_eat);
	printf("philo->time_to_sleep\t\t:\t%d\n", philo->time_to_sleep);
	printf("philo->nbrs_time_eat\t\t:\t%d\n", philo->nbrs_time_eat);
	printf("philo->thread\t\t\t:\t%p\n", &philo->thread);
	printf("philo->sv\t\t\t:\t%p\n", &philo->sv);
	dbfork(philo->fork);
	printf("philo->next\t\t\t:\t%p\n", philo->next);
}

void	dbfork(t_fork *fork)
{
	printf("fork->is_used\t\t\t:\t%d\n", fork->is_used);
	printf("fork->mutex\t\t\t:\t%p\n", &fork->mutex);
}
