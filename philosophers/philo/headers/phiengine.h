/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phiengine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 02:39:05 by lray              #+#    #+#             */
/*   Updated: 2023/06/04 02:53:29 by lray             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHIENGINE_H
# define PHIENGINE_H

# include "philo.h"

# define ALIVE 0
# define DEAD 1

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

void		threads_start(t_context *ctx);
void		threads_wait(t_context *ctx);

void		ft_puterror(char *msg);
int			ft_strlen(char *str);
int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);

#endif
