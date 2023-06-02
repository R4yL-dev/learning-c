/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:54:20 by lray              #+#    #+#             */
/*   Updated: 2023/06/01 16:27:38 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*philos_list_init(int *params)
{
	t_philo	*head;
	t_philo	*prev;
	t_philo	*new;
	int		i;

	head = philo_init(1);
	head->next = head;
	if (params[0] > 1)
	{
		prev = head;
		i = 1;
		while (i < params[0])
		{
			new = philo_init(i + 1);
			if (!new)
				return (NULL);
			prev->next = new;
			prev = new;
			i++;
		}
		new->next = head;
	}
	return (head);
}

void	philos_list_show(t_philo *head)
{
	t_philo	*ptr;

	ptr = head;
	while (1)
	{
		philo_show(ptr);
		ptr = ptr->next;
		if (ptr->id == 1)
			break ;
	}
}

void	philos_list_delete(t_philo *head)
{
	t_philo	*ptr;
	t_philo *next;
	int		nbrs_philo;

	ptr = head;
	nbrs_philo = 0;
	while (1)
	{
		nbrs_philo++;
		if (ptr->next->id == 1)
			break ;
		ptr = ptr->next;
	}
	ptr = head;
	while (nbrs_philo > 0)
	{
		next = ptr->next;
		philo_delete(ptr);
		ptr = next;
		nbrs_philo--;
	}


}

/* void	philos_run(t_context *ctx)
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

	while(nbrs_threads)
	{
		pthread_join(philo->thread, (void **)&resp);
		//pthread_detach(philo->thread);
		philo = philo->next;
		nbrs_threads--;
	}
} */

/* void	*philos_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->id == 1)
	{
		usleep(8000000);
		printf("JE SUIS MORT\n");
	}
	else
	{
		printf("JE SUIS THRED #%d\n",philo->id);
		usleep(400000);
	}
	return (NULL);
} */
