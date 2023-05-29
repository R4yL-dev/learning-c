/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:54:20 by lray              #+#    #+#             */
/*   Updated: 2023/05/22 19:10:56 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philos_init(t_context *ctx, int *params)
{
	t_philo	*head;
	t_philo	*prev;
	t_philo	*new;
	int		i;

	head = philo_new();
	philo_set(head, params, 1);
	head->sv = ctx->supervisor;
	head->next = head;
	if (params[0] > 1)
	{
		prev = head;
		i = 1;
		while (i < params[0])
		{
			new = philo_new();
			if (!new)
				return (NULL);
			philo_set(new, params, i + 1);
			new->sv = ctx->supervisor;
			prev->next = new;
			prev = new;
			i++;
		}
		new->next = head;
	}
	return (head);
}

void	philos_run(t_context *ctx)
{
	t_philo	*philo;
	int		nbrs_threads;
	int		*resp;

	philo = ctx->philos;
	nbrs_threads = ctx->nbrs_philos;
	while(nbrs_threads)
	{
		pthread_create(&philo->thread, NULL, philos_routine, philo);
		philo = philo->next;
		nbrs_threads--;
	}
	while (1)
	{

	}
	while(nbrs_threads)
	{
		pthread_join(philo->thread, (void **)&resp);
		if (*resp == 0)
			ctx->supervisor->is_a_philo_dead = 1;
		//pthread_detach(philo->thread);
		philo = philo->next;
		nbrs_threads--;
	}
}

void	*philos_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->id == 1)
	{
		usleep(8000000);
		philo->sv->is_a_philo_dead = 1;
		printf("JE SUIS MORT\n");
	}
	else
	{
		while (!philo->sv->is_a_philo_dead)
		{
			printf("JE SUIS THRED #%d\n",philo->id);
			usleep(400000);
		}

	}
	//dbphilo(philo);
	/* pthread_mutex_lock(&philo->fork->mutex);
	thread_say_take_his_fork(philo);
	pthread_mutex_lock(&philo->next->fork->mutex);
	thread_say_take_other_fork(philo);
	thread_say_start_eating(philo);
	usleep(400000);
	thread_say_stop_eating(philo);
	thread_say_down_other_fork(philo);
	pthread_mutex_unlock(&philo->next->fork->mutex);
	thread_say_down_his_fork(philo);
	pthread_mutex_unlock(&philo->fork->mutex); */
	return (NULL);
}

void	philos_delete(t_philo *head)
{
	t_philo	*next;

	next = head->next;
	while (next != head)
		next = philo_delete(&next);
	philo_delete(&head);
}
