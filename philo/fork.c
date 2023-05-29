/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:52:03 by lray              #+#    #+#             */
/*   Updated: 2023/05/20 17:22:59 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_fork	*fork_new()
{
	t_fork	*new;

	new = malloc(sizeof(t_fork));
	if (!new)
	{
		ft_puterror("Malloc failed");
		return (NULL);
	}
	new->is_used = 0;
	if (pthread_mutex_init(&new->mutex, NULL) != 0)
	{
		ft_puterror("Mutex creation failed");
		return (NULL);
	}
	return (new);
}

void	fork_delete(t_fork **fork)
{
	pthread_mutex_t	*mutex;

	mutex = &(*fork)->mutex;
	pthread_mutex_destroy(mutex);
}
