/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:52:03 by lray              #+#    #+#             */
/*   Updated: 2023/05/18 20:58:14 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fork_init(t_fork *fork)
{
	int	resp;

	fork->is_used = 0;
	resp = pthread_mutex_init(&fork->mutex, NULL);
	if (resp != 0)
	{
		ft_puterror("Mutex init failed");
		return (0);
	}
	return (1);
}
