/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:40:19 by lray              #+#    #+#             */
/*   Updated: 2023/05/18 21:36:45 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>

# define NBRS_THREAD 1

typedef struct s_fork
{
	int				is_used;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	int			id;
	useconds_t	time_to_die;
	useconds_t	time_to_eat;
	useconds_t	time_to_sleep;
	int			nbrs_time_eat;
	pthread_t	thread;
	t_fork		fork;
	struct s_philo *next;
}	t_philo;

int		args_parser(int *argc, char ***argv, int *args);

t_philo	*philo_init(t_philo *philos, int id, int *params);
void	philo_add(t_philo *head, int *params);

int		fork_init(t_fork *fork);

void	ft_puterror(char *msg);
int		ft_strlen(char *str);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);

#endif
