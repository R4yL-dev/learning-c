/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:40:19 by lray              #+#    #+#             */
/*   Updated: 2023/05/21 00:17:01 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <time.h>
# include <sys/types.h>
# include <sys/time.h>

typedef struct s_supervisor
{
	int				is_a_philo_dead;
	pthread_t		thread;
	pthread_mutex_t	mutex_print;
}	t_supervisor;

typedef struct s_fork
{
	int				is_used;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	int				id;
	__useconds_t	time_to_die;
	__useconds_t	time_to_eat;
	__useconds_t	time_to_sleep;
	int				nbrs_time_eat;
	pthread_t		thread;
	t_fork			*fork;
	t_supervisor	*sv;
	struct s_philo	*next;
}	t_philo;

typedef struct s_context
{
	struct timeval 	time_start;
	int				nbrs_philos;
	t_supervisor	*supervisor;
	t_philo			*philos;
}	t_context;


int				args_parser(int *argc, char ***argv, int *args);

t_context		*context_init(int *params);

t_philo			*philos_init(t_context *ctx, int *params);
void			philos_run(t_context *ctx);
void			*philos_routine(void *arg);
void			philos_delete(t_philo *head);

t_philo			*philo_new();
void			philo_set(t_philo *philo, int *params, int id);
t_philo			*philo_delete(t_philo **philo);

t_fork			*fork_new();
void			fork_delete(t_fork **fork);

void			*supervisor_routine(void *arg);
t_supervisor	*supervisor_init();

void			simulation_run(t_context *ctx);

void			thread_say_take_his_fork(t_philo *philo);
void			thread_say_take_other_fork(t_philo *philo);
void			thread_say_start_eating(t_philo *philo);
void			thread_say_stop_eating(t_philo *philo);
void			thread_say_down_his_fork(t_philo *philo);
void			thread_say_down_other_fork(t_philo *philo);

void			ft_puterror(char *msg);
int				ft_strlen(char *str);
int				ft_atoi(const char *nptr);
int				ft_isdigit(int c);

void			dbcontext(t_context *ctx);
void			dbsupervisor(t_supervisor *sv);
void			dbphilos(t_philo *head);
void			dbphilo(t_philo *philo);
void			dbfork(t_fork *fork);

#endif
