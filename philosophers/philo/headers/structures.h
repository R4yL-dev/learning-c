/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 02:42:14 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 17:45:23 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "philo.h"

typedef struct s_timing
{
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	long int	start;
}	t_timing;

typedef struct s_philo
{
	int				id;
	int				status;
	int				nbrs_time_eat;
	long int		last_meal_time;
	t_timing		*timing;
	pthread_mutex_t	fork;
	pthread_t		thread;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*status_mutex;
	pthread_mutex_t	*nbrs_meal_mutex;
	struct s_philo	*next;
}	t_philo;

typedef struct s_context
{
	int				all_philos_alive;
	int				nbrs_philos;
	int				nbrs_time_eat;
	t_timing		*timing;
	t_philo			*philos;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	status_mutex;
	pthread_mutex_t	nbrs_meal_mutex;
}	t_context;
#endif
