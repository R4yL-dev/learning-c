/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:40:19 by lray              #+#    #+#             */
/*   Updated: 2023/06/02 13:14:09 by lray             ###   ########.fr       */
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
	t_timing		*timing;
	pthread_mutex_t	fork;
	pthread_t		thread;
	pthread_mutex_t	*print_mutex;
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
}	t_context;

int			*args_parser(int argc, char **argv);

t_context	*context_init(int *params);
void		context_show(t_context *ctx);
void		context_delete(t_context *ctx);

t_philo		*philos_list_init(int *params);
void		philos_list_show(t_philo *head);
void		philos_list_delete(t_philo *head);

t_philo		*philo_init(int id);
void		philo_talk(t_philo *philo, char *msg);
void		philo_show(t_philo *philo);
void		philo_delete(t_philo *philo);

t_timing	*timing_init(int *params);
void		timing_show(t_timing *timing);
void		timing_delete(t_timing *timing);

long int	time_get_current(void);
long int	time_get_interval(long int start, long int end);
void		time_sleep(long int ms);

void		ft_puterror(char *msg);
int			ft_strlen(char *str);
int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);

#endif
